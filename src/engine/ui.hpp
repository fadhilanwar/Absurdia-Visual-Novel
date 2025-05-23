#pragma once

#include <vector>
#include <functional>

#include "canvas.hpp"


struct Text
{
    int x, y;
    std::string text;
    TextStyle style;
    int fontSize;
    sf::Color color;
};

struct ButtonPrimitive
{
    int x, y;
    int width, height;

    bool isMouseDown;
    std::function<void(void *)> onClick;
    void *onClickParameter;
};

struct Button
{
    ButtonPrimitive button;
    std::string text;
    int fontSize;
    sf::Color textColor;
    sf::Texture backgroundImage;
};

struct Rectangle
{
    int x, y;
    int width, height;
    sf::Color color;
};

struct Image
{
    int x, y;
    int width, height;
    sf::Texture image;
    bool stretch;
};

enum UIElementType
{
    TEXT,
    BUTTON,
    RECTANGLE,
    IMAGE
    // BUTTON_WITH_TEXT
};

struct UIElement
{
    int id;
    UIElementType type;
    void *properties;
};

struct UI
{
    bool isDirty;
    bool isRequireCopy;
    Canvas *canvas;

    std::vector<UIElement*> elements;

    bool isMouseDown;
    bool isHoveringButton;

    ~UI()
    {
        delete canvas;
        for (UIElement *elem : elements)
        {
            if (elem->type == UIElementType::TEXT)
                delete (Text *)elem->properties;
            else if (elem->type == UIElementType::BUTTON)
                delete (Button *)elem->properties;
            else if (elem->type == UIElementType::RECTANGLE)
                delete (Rectangle *)elem->properties;
            else if (elem->type == UIElementType::IMAGE)
                delete (Image *)elem->properties;
        }
    }
};

UI *UI_Create();
void UI_HitTest(UI *ui, sf::Window *window);
void UI_ResetCursor(UI *ui, sf::Window *window);
UIElement *UI_AddText(UI *ui, UIElement *insertAfter, int x, int y, std::string text, TextStyle style, int fontSize, sf::Color color);
UIElement *UI_AddButton(UI *ui, UIElement *insertAfter, int x, int y, int width, int height, std::string text, int fontSize, sf::Color textColor, std::string backgroundFilePath, std::function<void(void *)> onClick, void *onClickParameter);
UIElement *UI_AddRectangle(UI *ui, UIElement *insertAfter, int x, int y, int width, int height, sf::Color color);
UIElement *UI_AddImage(UI *ui, UIElement *insertAfter, int x, int y, int width, int height, bool stretch, std::string imageFilePath);
void UI_CopyCanvasToImage(UI *ui, Image *targetImage, Canvas *srcCanvas);
void UI_RequestUpdate(UI *ui);
void UI_DrawAll(UI *ui);