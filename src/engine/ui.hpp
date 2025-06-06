#pragma once

#include <vector>
#include <functional>

#include "engine_window.hpp"
#include "canvas.hpp"

struct Text
{
    int x, y;
    std::string text;
    std::string fontPath;
    int fontSize;
    sf::Color color;
};

struct Button
{
    int x, y;
    int width, height;
    sf::Vector2i horizontalPadding, verticalPadding;

    std::string text;
    std::string fontPath;
    int fontSize;
    sf::Color textColor;
    sf::Texture backgroundImage;

    bool isMouseDown;
    std::function<void(void *)> onClick;
    void *onClickParameter;
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

struct InputField
{
    int x, y;
    int width, height;
    sf::Vector2i horizontalPadding, verticalPadding;

    std::string placeholderText;
    std::string text;
    int maxLength;
    std::string fontPath;
    sf::Color textColor;
    sf::Texture backgroundImage;
    sf::Texture focusedBackgroundImage;
};
enum UIElementType
{
    TEXT,
    BUTTON,
    RECTANGLE,
    IMAGE,
    INPUT_FIELD
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

    std::vector<UIElement *> elements;
    UIElement *focusedElement = nullptr;
    UIElement *hoveredElement = nullptr;

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

// Buat UI (hanya boleh dipanggil sama PageManager/SceneManager)
UI *UI_Create();
// Tes buat event (hanya boleh dipanggil sama PageManager/SceneManager)
void UI_EventTest(UI *ui, EngineWindow *engineWindow);
// Gambar UI (hanya boleh dipanggil sama UI/PageManager/SceneManager)
void UI_DrawAll(UI *ui);
// Request buat ngegambar UI
void UI_RequestUpdate(UI *ui);

// Tambah teks
UIElement *UI_AddText(UI *ui, UIElement *insertAfter, int x, int y, std::string text, std::string fontPath, int fontSize, sf::Color color);

// Tambah button
UIElement *UI_AddButton(UI *ui, UIElement *insertAfter, int x, int y, int width, int height, sf::Vector2i horizontalPadding, sf::Vector2i verticalPadding, std::string text, std::string fontPath, int fontSize, sf::Color textColor, std::string backgroundFilePath, std::function<void(void *)> onClick, void *onClickParameter);

// Tambah kotak
UIElement *UI_AddRectangle(UI *ui, UIElement *insertAfter, int x, int y, int width, int height, sf::Color color);

// Tambah foto
UIElement *UI_AddImage(UI *ui, UIElement *insertAfter, int x, int y, int width, int height, bool stretch, std::string imageFilePath);

// Tambah input field
UIElement *UI_AddInputField(UI *ui, UIElement *insertAfter, int x, int y, int width, int height, sf::Vector2i horizontalPadding, sf::Vector2i verticalPadding, std::string placeholderText, int maxLength, std::string fontPath, sf::Color textColor, std::string backgroundFilePath, std::string focusedBackgroundFilePath);
// Ambil isi teks input field
std::string UI_GetInputText(UIElement *);

void UI_CopyCanvasToImage(UI *ui, Image *targetImage, Canvas *srcCanvas);
void UI_ResetCursor(UI *ui, EngineWindow *engineWindow);
