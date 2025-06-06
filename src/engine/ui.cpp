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

void UI_EventTest(UI *ui, EngineWindow *engineWindow)
{
    // Dapatkan posisi mouse
    sf::Vector2i mousePos = sf::Mouse::getPosition(engineWindow->window);

    // bool isHoveringButton = false;
    // bool isHoveringTextField = false;
    bool needRedraw = false;
    UIElement *_hoveredElement = nullptr;
    UIElement *_focusedElement = ui->focusedElement;

    // Tes satu-satu semua elemen dari belakang,
    // apabila sudah ada elemen yang di-"hover", stop iterasi
    for (auto it = ui->elements.rbegin(); it != ui->elements.rend(); ++it)
    {
        UIElement *elem = *it;

        // Apabila elemen adalah Button
        if (elem->type == UIElementType::BUTTON /*  || elem.type == UIElementType::BUTTON_WITH_TEXT */)
        {
            Button *button = (Button *)elem->properties;

            if (mousePos.x >= button->x && mousePos.x <= button->x + button->width &&
                mousePos.y >= button->y && mousePos.y <= button->y + button->height)
            {
                _hoveredElement = elem;
                // isHoveringButton = true;

                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                {
                    if (!ui->isMouseDown)
                    {
                        ui->isMouseDown = true;
                        _focusedElement = elem;
                        if (button->onClick != nullptr)
                            button->onClick(button->onClickParameter);
                    }
                }
                else
                {
                    if (ui->isMouseDown)
                        ui->isMouseDown = false;
                }

                break;
            }
        }
        else if (elem->type == UIElementType::INPUT_FIELD)
        {
            InputField *inputField = (InputField *)elem->properties;

            if (mousePos.x >= inputField->x && mousePos.x <= inputField->x + inputField->width &&
                mousePos.y >= inputField->y && mousePos.y <= inputField->y + inputField->height)
            {
                _hoveredElement = elem;

                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                {
                    if (!ui->isMouseDown)
                    {
                        ui->isMouseDown = true;
                        _focusedElement = elem;
                        needRedraw = true;
                    }
                }
                else
                {
                    if (ui->isMouseDown)
                        ui->isMouseDown = false;
                }

                break;
            }
        }
    }

    // Cabut elemen fokus kalau mouse dipencet bukan di elemen yang bisa diklik
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && _hoveredElement == nullptr)
    {
        _focusedElement = nullptr;
        needRedraw = true;
    }

    // Cek hovered element
    if (_hoveredElement != nullptr)
    {
        if (_hoveredElement->type == UIElementType::BUTTON)
        {
            auto cursor = sf::Cursor::createFromSystem(sf::Cursor::Type::Hand).value();
            engineWindow->window.setMouseCursor(cursor);
        }
        else if (_hoveredElement->type == UIElementType::INPUT_FIELD)
        {
            auto cursor = sf::Cursor::createFromSystem(sf::Cursor::Type::Text).value();
            engineWindow->window.setMouseCursor(cursor);
        }
    }
    else if (_hoveredElement == nullptr && ui->hoveredElement != nullptr)
    {
        auto cursor = sf::Cursor::createFromSystem(sf::Cursor::Type::Arrow).value();
        engineWindow->window.setMouseCursor(cursor);
        ui->isHoveringButton = false;
    }

    // Cek focused element
    if (_focusedElement != nullptr)
    {
        if (_focusedElement->type == UIElementType::INPUT_FIELD)
        {
            InputField *inputField = (InputField *)_focusedElement->properties;
            if (engineWindow->inputtedText == 8)
            {
                if (!inputField->text.empty())
                {
                    inputField->text.pop_back();
                    needRedraw = true;
                }
            }
            else if (engineWindow->inputtedText != '\0' && inputField->text.size() <= inputField->maxLength)
            {
                inputField->text += engineWindow->inputtedText;
                needRedraw = true;
            }
        }
    }

    ui->hoveredElement = _hoveredElement;
    if (ui->focusedElement != _focusedElement)
        ui->focusedElement = _focusedElement;

    if (needRedraw)
        UI_RequestUpdate(ui);
}

void UI_ResetCursor(UI *ui, EngineWindow *engineWindow)
{
    auto cursor = sf::Cursor::createFromSystem(sf::Cursor::Type::Arrow).value();
    engineWindow->window.setMouseCursor(cursor);
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

UIElement *UI_AddText(UI *ui, UIElement *insertAfter, int x, int y, std::string text, std::string fontPath, int fontSize, sf::Color color)
{
    Text *textElement = new Text{
        .x = x,
        .y = y,
        .text = text,
        .fontPath = fontPath,
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

UIElement *UI_AddButton(UI *ui, UIElement *insertAfter, int x, int y, int width, int height, sf::Vector2i horizontalPadding, sf::Vector2i verticalPadding, std::string text, std::string fontPath, int fontSize, sf::Color textColor, std::string backgroundFilePath, std::function<void(void *)> onClick, void *onClickParameter)
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
        .x = x,
        .y = y,
        .width = width,
        .height = height,
        .horizontalPadding = horizontalPadding,
        .verticalPadding = verticalPadding,
        .text = text,
        .fontPath = fontPath,
        .fontSize = fontSize,
        .textColor = textColor,
        .backgroundImage = backgroundImage,
        .onClick = onClick,
        .onClickParameter = onClickParameter,
    };
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

UIElement *UI_AddInputField(
    UI *ui, UIElement *insertAfter, int x, int y, int width, int height, sf::Vector2i horizontalPadding, sf::Vector2i verticalPadding, std::string placeholderText, int maxLength, std::string fontPath, sf::Color textColor, std::string backgroundFilePath, std::string focusedBackgroundFilePath)
{
    InputField *inputField = new InputField{
        .x = x,
        .y = y,
        .width = width,
        .height = height,
        .horizontalPadding = horizontalPadding,
        .verticalPadding = verticalPadding,
        .placeholderText = placeholderText,
        .maxLength = maxLength,
        .fontPath = fontPath,
        .textColor = textColor,
        .backgroundImage = sf::Texture(GetExePath() + backgroundFilePath),
        .focusedBackgroundImage = sf::Texture(GetExePath() + focusedBackgroundFilePath)};
    UIElement *element = new UIElement{
        .id = rand() % 1000001,
        .type = UIElementType::INPUT_FIELD,
        .properties = inputField};

    m_UI_AddElement(ui, element, insertAfter);
    ui->isDirty = true;

    return element;
}

std::string UI_GetInputText(UIElement *element)
{
    if (element->type == UIElementType::INPUT_FIELD)
    {
        InputField *inputField = (InputField *)element->properties;
        return inputField->text;
    }
    return "";
};

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
            Canvas_DrawText(ui->canvas, text->x, text->y, text->text, text->fontPath, text->fontSize, text->color);
        }
        else if (elem->type == UIElementType::BUTTON)
        {
            Button *button = (Button *)elem->properties;
            Canvas_DrawTexture(
                ui->canvas,
                button->x, button->y,
                button->width, button->height,
                true,
                &button->backgroundImage);
            Canvas_DrawText(
                ui->canvas,
                button->x + button->horizontalPadding.x,
                button->y + button->verticalPadding.x,
                button->width - button->horizontalPadding.x - button->horizontalPadding.y,
                button->height - button->verticalPadding.x - button->verticalPadding.y,
                button->text,
                button->fontPath,
                Alignment::Center,
                button->fontSize,
                button->textColor);
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
            Canvas_DrawTexture(
                ui->canvas,
                inputField->x, inputField->y,
                inputField->width, inputField->height,
                true,
                ui->focusedElement == elem ? &inputField->focusedBackgroundImage : &inputField->backgroundImage);
            if (inputField->text.empty())
            {
                sf::Color placeholderColor(inputField->textColor.r, inputField->textColor.g, inputField->textColor.b, 80);
                Canvas_DrawText(
                    ui->canvas,
                    inputField->x + inputField->horizontalPadding.x,
                    inputField->y + inputField->verticalPadding.x,
                    inputField->width - inputField->horizontalPadding.x - inputField->horizontalPadding.y,
                    inputField->height - inputField->verticalPadding.x - inputField->verticalPadding.y,
                    inputField->placeholderText,
                    inputField->fontPath,
                    Alignment::Left,
                    16,
                    placeholderColor);
            }
            else
            {
                Canvas_DrawText(
                    ui->canvas,
                    inputField->x + inputField->horizontalPadding.x,
                    inputField->y + inputField->verticalPadding.x,
                    inputField->width - inputField->horizontalPadding.x - inputField->horizontalPadding.y,
                    inputField->height - inputField->verticalPadding.x - inputField->verticalPadding.y,
                    inputField->text,
                    inputField->fontPath,
                    Alignment::Left,
                    16,
                    inputField->textColor);
            }
        }
    }
    Canvas_Update(ui->canvas);

    ui->isDirty = false;
    ui->isRequireCopy = true;
}