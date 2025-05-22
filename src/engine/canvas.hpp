#pragma once

#include <map>
#include <SFML/Graphics.hpp>

#include "../umum.hpp"

enum TextStyle
{
    NORMAL,
    BOLD
};

enum TextAlignment
{
    LEFT,
    CENTER,
    RIGHT
};

struct Canvas
{
    bool isRenderTextureFromExternal = false;
    sf::RenderTexture *renderTexture;

    std::map<std::string, sf::Texture> textureCache;
    sf::Font normalFont;
    sf::Font boldFont;

    ~Canvas()
    {
        if (!isRenderTextureFromExternal)
            delete renderTexture;
    }
};

Canvas *Canvas_Create();
Canvas *Canvas_Create(sf::RenderTexture *renderTexture);
void Canvas_Clear(Canvas *canvas);
void Canvas_Update(Canvas *canvas);
void Canvas_DrawRect(Canvas *canvas, int x, int y, int width, int height, sf::Color color);
void Canvas_DrawCircle(Canvas *canvas, int x, int y, int radius, sf::Color color);
void Canvas_DrawText(Canvas *canvas, int x, int y, std::string text, TextStyle style, int fontSize, sf::Color color);
void Canvas_DrawText(Canvas *canvas, int x, int y, int width, int height, std::string text, TextStyle style, TextAlignment alignment, int fontSize, sf::Color color);
void Canvas_DrawSprite(Canvas *canvas, int x, int y, sf::Sprite *sprite);
void Canvas_DrawSprite(Canvas *canvas, int x, int y, int width, int height, bool stretch, sf::Sprite *sprite);
void Canvas_DrawTexture(Canvas *canvas, int x, int y, sf::Texture *texture);
void Canvas_DrawTexture(Canvas *canvas, int x, int y, int width, int height, bool stretch, sf::Texture *texture);
void Canvas_DrawImage(Canvas *canvas, int x, int y, std::string filePath);
void Canvas_DrawImage(Canvas *canvas, int x, int y, std::string filePath, int opacity);
void Canvas_Copy(Canvas *targetCanvas, Canvas *srcCanvas);
sf::Texture Canvas_GetTexture(Canvas *canvas);