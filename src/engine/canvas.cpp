#include "canvas.hpp"

Canvas *Canvas_Create()
{
    sf::RenderTexture *texture = new sf::RenderTexture({1000u, 550u});
    Canvas *canvas = Canvas_Create(texture);
    canvas->isRenderTextureFromExternal = false;
    return canvas;
}

Canvas *Canvas_Create(sf::RenderTexture *renderTexture)
{
    Canvas *canvas = new Canvas();
    canvas->isRenderTextureFromExternal = true;
    canvas->renderTexture = renderTexture;

    canvas->normalFont = sf::Font(GetExePath() + "Roboto-Regular.ttf");
    canvas->boldFont = sf::Font(GetExePath() + "Roboto-SemiBold.ttf");

    return canvas;
}

void Canvas_Clear(Canvas *canvas)
{
    canvas->renderTexture->clear(sf::Color(0, 0, 0));
}

void Canvas_Update(Canvas *canvas)
{
    canvas->renderTexture->display();
}

void Canvas_DrawRect(Canvas *canvas, int x, int y, int width, int height, sf::Color color)
{
    sf::RectangleShape shape({(float)width, (float)height});
    shape.setFillColor(color);
    shape.setPosition({(float)x, (float)y});

    canvas->renderTexture->draw(shape);
}

void Canvas_DrawCircle(Canvas *canvas, int x, int y, int radius, sf::Color color)
{
    sf::CircleShape shape(radius);
    shape.setFillColor(color);
    shape.setPosition({(float)x, (float)y});

    canvas->renderTexture->draw(shape);
}

void Canvas_DrawText(Canvas *canvas, int x, int y, std::string text, TextStyle style, int fontSize, sf::Color color)
{
    sf::Font *font;
    if (style == TextStyle::NORMAL)
    {
        font = &canvas->normalFont;
    }
    else if (style == TextStyle::BOLD)
    {
        font = &canvas->boldFont;
    }

    sf::Text textBlock(*font);
    textBlock.setString(text);
    textBlock.setCharacterSize(fontSize);
    textBlock.setFillColor(color);
    textBlock.setPosition({(float)x, (float)y});

    canvas->renderTexture->draw(textBlock);
}

void Canvas_DrawText(Canvas *canvas, int x, int y, int width, int height, std::string text, TextStyle style, TextAlignment alignment, int fontSize, sf::Color color)
{
    sf::Font *font;
    if (style == TextStyle::NORMAL)
    {
        font = &canvas->normalFont;
    }
    else if (style == TextStyle::BOLD)
    {
        font = &canvas->boldFont;
    }

    sf::Text textBlock(*font);
    textBlock.setString(text);
    textBlock.setCharacterSize(fontSize);
    textBlock.setFillColor(color);

    sf::FloatRect rect = textBlock.getLocalBounds();
    float posX, posY;
    if (alignment == TextAlignment::LEFT)
    {
        posX = x;
        posY = y + (height / 2) - (rect.size.y);
    }
    else if (alignment == TextAlignment::CENTER)
    {
        posX = x + (width / 2) - (rect.size.x / 2);
        posY = y + (height / 2) - (rect.size.y);
    }
    else
    {
        posX = x + width - rect.size.x;
        posY = y + (height / 2) - (rect.size.y);
    }
    textBlock.setPosition({posX, posY});

    canvas->renderTexture->draw(textBlock);
}

void Canvas_DrawSprite(Canvas *canvas, int x, int y, sf::Sprite *sprite)
{
    sprite->setPosition({(float)x, (float)y});
    canvas->renderTexture->draw(*sprite);
}

void Canvas_DrawSprite(Canvas *canvas, int x, int y, int width, int height, bool stretch, sf::Sprite *sprite)
{
    sprite->setPosition({(float)x, (float)y});
    if (stretch)
    {
        sf::Vector2u textureRect = sprite->getTexture().getSize();
        float scaleW = (float)width / textureRect.x;
        float scaleH = (float)height / textureRect.y;
        sprite->setScale({scaleW, scaleH});
    }
    else
    {
        sprite->setTextureRect(sf::IntRect({0, 0}, {width, height}));
    }
    canvas->renderTexture->draw(*sprite);
}

void Canvas_DrawTexture(Canvas *canvas, int x, int y, sf::Texture *texture)
{
    sf::Sprite sprite = sf::Sprite(*texture);
    Canvas_DrawSprite(canvas, x, y, &sprite);
}

void Canvas_DrawTexture(Canvas *canvas, int x, int y, int width, int height, bool stretch, sf::Texture *texture)
{
    sf::Sprite sprite = sf::Sprite(*texture);
    Canvas_DrawSprite(canvas, x, y, width, height, stretch, &sprite);
}

void Canvas_DrawImage(Canvas *canvas, int x, int y, std::string filePath)
{
    std::string correctFilePath = GetExePath() + filePath;
    if (canvas->textureCache.count(correctFilePath) == 0)
    {
        sf::Texture texture = sf::Texture(correctFilePath);
        Canvas_DrawTexture(canvas, x, y, &texture);
        canvas->textureCache[correctFilePath] = texture;
    }
    else
    {
        Canvas_DrawTexture(canvas, x, y, &canvas->textureCache[correctFilePath]);
    }
}

void Canvas_DrawImage(Canvas *canvas, int x, int y, std::string filePath, int opacity)
{
}

void Canvas_Copy(Canvas *targetCanvas, Canvas *srcCanvas)
{
    sf::Texture texture = srcCanvas->renderTexture->getTexture();
    sf::Sprite sprite(texture);
    targetCanvas->renderTexture->draw(sprite);
    targetCanvas->renderTexture->display();
}

sf::Texture Canvas_GetTexture(Canvas *canvas)
{
    return canvas->renderTexture->getTexture();
}

// void Canvas::drawButton(int x, int y, std::string text, int fontSize, sf::Color buttonColor, sf::Color textColor, std::function<void()> callback)
// {
//     // if (!checkScene(scene)) return;

//     sf::Text textBlock(_font);
//     textBlock.setString(text);
//     textBlock.setCharacterSize(fontSize);
//     textBlock.setFillColor(textColor);
//     textBlock.setStyle(sf::Text::Style::Bold);
//     textBlock.setPosition({ x + 4, y + 4 });

//     auto textBlockBound = textBlock.getGlobalBounds();

//     sf::RectangleShape shape({ textBlockBound.size.x + 12, textBlockBound.size.y + 16 });
//     shape.setFillColor(sf::Color(buttonColor.r, buttonColor.g, buttonColor.b, 40));
//     shape.setOutlineColor(buttonColor);
//     shape.setOutlineThickness(2);
//     shape.setPosition({x, y});

//     _renderTexture->draw(shape);
//     _renderTexture->draw(textBlock);
//     _isSceneDirty = true;
// }