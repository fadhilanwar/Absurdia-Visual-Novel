#include "ui.hpp"

#include <algorithm>
#include <iostream>

UI *UI_Create()
{
    Canvas *canvas = Canvas_Create();
    Canvas_Clear(canvas);
    Canvas_Update(canvas);

    UI *ui = new UI{
        .canvas = canvas};
    return ui;
}

void UI_HitTest(UI *ui, sf::Window *window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);

    bool isHoveringButton = false;

    for (const UIElement *elem : ui->elements)
    {
        if (elem->type == UIElementType::BUTTON /*  || elem.type == UIElementType::BUTTON_WITH_TEXT */)
        {
            ButtonPrimitive button = (ButtonPrimitive)((Button *)elem->properties)->button;
            // if (elem.type == UIElementType::BUTTON)
            // {
            //     button = (ButtonPrimitive)((Button *)elem.properties)->button;
            // }

            if (mousePos.x >= button.x && mousePos.x <= button.x + button.width &&
                mousePos.y >= button.y && mousePos.y <= button.y + button.height)
            {
                isHoveringButton = true;

                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                {
                    if (!ui->isMouseDown)
                    {
                        ui->isMouseDown = true;
                        if (button.onClick != nullptr)
                            button.onClick(button.onClickParameter);
                    }
                }
                else
                {
                    if (ui->isMouseDown)
                        ui->isMouseDown = false;
                }
            }
        }
    }

    if (!ui->isHoveringButton && isHoveringButton)
    {
        auto cursor = sf::Cursor::createFromSystem(sf::Cursor::Type::Hand).value();
        window->setMouseCursor(cursor);
        ui->isHoveringButton = true;
    }
    else if (ui->isHoveringButton && !isHoveringButton)
    {
        auto cursor = sf::Cursor::createFromSystem(sf::Cursor::Type::Arrow).value();
        window->setMouseCursor(cursor);
        ui->isHoveringButton = false;
    }
}

void UI_ResetCursor(UI *ui, sf::Window *window)
{
    auto cursor = sf::Cursor::createFromSystem(sf::Cursor::Type::Arrow).value();
    window->setMouseCursor(cursor);
}

void m_UI_AddElement(UI *ui, UIElement *element, UIElement *insertAfter)
{
    if (insertAfter != nullptr)
    {
        auto it = std::find_if(ui->elements.begin(), ui->elements.end(),
                               [&](UIElement *item)
                               { return item->id == insertAfter->id; });
        if (it != ui->elements.end())
        {
            ui->elements.insert(it + 1, element);
        }
        else
        {
            std::cout << "Gagal tambah elemen UI! elemen UI insertAfter tidak ada di daftar elemen UI yang ada. Elemen UI akan ditambah di akhir daftar elemen UI.\n";
            ui->elements.push_back(element);
        }
    }
    else
    {
        ui->elements.push_back(element);
    }
}

UIElement *UI_AddText(UI *ui, UIElement *insertAfter, int x, int y, std::string text, TextStyle style, int fontSize, sf::Color color)
{
    Text *textElement = new Text{
        .x = x,
        .y = y,
        .text = text,
        .style = style,
        .fontSize = fontSize,
        .color = color};
    UIElement *element = new UIElement{
        .id = rand() % 1000001,
        .type = UIElementType::TEXT,
        .properties = textElement};

    m_UI_AddElement(ui, element, insertAfter);
    ui->isDirty = true;

    return element;
}

UIElement *UI_AddButton(UI *ui, UIElement *insertAfter, int x, int y, int width, int height, std::string text, int fontSize, sf::Color textColor, std::string backgroundFilePath, std::function<void(void *)> onClick, void *onClickParameter)
{
    sf::Texture backgroundImage;
    if (backgroundFilePath == "")
    {
        backgroundImage = sf::Texture(GetExePath() + "emoji2.png");
    }
    else
    {
        backgroundImage = sf::Texture(GetExePath() + backgroundFilePath);
    }

    Button *buttonElement = new Button{
        .button = ButtonPrimitive{
            .x = x,
            .y = y,
            .width = width,
            .height = height,
            .onClick = onClick,
            .onClickParameter = onClickParameter},
        .text = text,
        .fontSize = fontSize,
        .textColor = textColor,
        .backgroundImage = backgroundImage};
    UIElement *element = new UIElement{
        .id = rand() % 1000001,
        .type = UIElementType::BUTTON,
        .properties = buttonElement};

    m_UI_AddElement(ui, element, insertAfter);
    ui->isDirty = true;

    return element;
}

UIElement *UI_AddRectangle(UI *ui, UIElement *insertAfter, int x, int y, int width, int height, sf::Color color)
{
    Rectangle *rectangleElem = new Rectangle{
        .x = x,
        .y = y,
        .width = width,
        .height = height,
        .color = color};
    UIElement *element = new UIElement{
        .id = rand() % 1000001,
        .type = UIElementType::RECTANGLE,
        .properties = rectangleElem};

    m_UI_AddElement(ui, element, insertAfter);
    ui->isDirty = true;

    return element;
}

UIElement *UI_AddImage(UI *ui, UIElement *insertAfter, int x, int y, int width, int height, bool stretch, std::string imageFilePath)
{
    sf::Texture image;
    if (imageFilePath != "")
    {
        image.loadFromFile(GetExePath() + imageFilePath);
    }

    Image *rectangleElem = new Image{
        .x = x,
        .y = y,
        .width = width,
        .height = height,
        .image = image,
        .stretch = stretch};
    UIElement *element = new UIElement{
        .id = rand() % 1000001,
        .type = UIElementType::IMAGE,
        .properties = rectangleElem};

    m_UI_AddElement(ui, element, insertAfter);
    ui->isDirty = true;

    return element;
}

void UI_CopyCanvasToImage(UI *ui, Image *targetImage, Canvas *srcCanvas)
{
    targetImage->image = Canvas_GetTexture(srcCanvas);
    ui->isDirty = true;
}

void UI_RequestUpdate(UI *ui)
{
    ui->isDirty = true;
}

void UI_DrawAll(UI *ui)
{
    Canvas_Clear(ui->canvas);

    for (const UIElement *elem : ui->elements)
    {
        if (elem->type == UIElementType::TEXT)
        {
            Text *text = (Text *)elem->properties;
            Canvas_DrawText(ui->canvas, text->x, text->y, text->text, text->style, text->fontSize, text->color);
        }
        else if (elem->type == UIElementType::BUTTON)
        {
            Button *button = (Button *)elem->properties;
            ButtonPrimitive &buttonPrim = button->button;
            Canvas_DrawTexture(ui->canvas, buttonPrim.x, buttonPrim.y, buttonPrim.width, buttonPrim.height, true, &button->backgroundImage);
            Canvas_DrawText(ui->canvas, buttonPrim.x, buttonPrim.y, buttonPrim.width, buttonPrim.height, button->text, TextStyle::BOLD, TextAlignment::CENTER, button->fontSize, button->textColor);
        }
        else if (elem->type == UIElementType::RECTANGLE)
        {
            Rectangle *rect = (Rectangle *)elem->properties;
            Canvas_DrawRect(ui->canvas, rect->x, rect->y, rect->width, rect->height, rect->color);
        }
        else if (elem->type == UIElementType::IMAGE)
        {
            Image *image = (Image *)elem->properties;
            Canvas_DrawTexture(ui->canvas, image->x, image->y, image->width, image->height, image->stretch, &image->image);
        }
        else if (elem->type == UIElementType::INPUT_FIELD)
        {
            InputField *inputField = (InputField *)elem->properties;
            Canvas_DrawTexture(ui->canvas, inputField->x, inputField->y, inputField->width, inputField->height, true, &inputField->backgroundImage);
            Canvas_DrawText(ui->canvas, inputField->x + 5, inputField->y + 5, inputField->text, TextStyle::NORMAL, 16, inputField->textColor);
        }
    }
    Canvas_Update(ui->canvas);

    ui->isDirty = false;
    ui->isRequireCopy = true;
}

UIElement* UI_AddInputField(
    UI* ui, UIElement* insertAfter, int x, int y, int width, int height, std::string placeholderText, int maxLength, sf::Color textColor, std::string backgroundFilePath) {
    InputField* inputField = new InputField{
        .x = x,
        .y = y,
        .width = width,
        .height = height,
        .text = placeholderText,
        .maxLength = maxLength,
        .textColor = textColor,
        .backgroundImage = sf::Texture(GetExePath() + backgroundFilePath)
    };
    UIElement* element = new UIElement{
        .id = rand() % 1000001,
        .type = UIElementType::INPUT_FIELD,
        .properties = inputField
    };

    m_UI_AddElement(ui, element, insertAfter);
    ui->isDirty = true;

    return element;
}

std::string UI_GetInputText(UIElement* element) {
    if (element->type == UIElementType::INPUT_FIELD) {
        InputField *inputField = (InputField *)element->properties;
        return inputField->text;
    }
    return "";
};