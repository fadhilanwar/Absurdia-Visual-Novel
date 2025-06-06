#include "canvas.hpp"

// =======================
// == Private Functions ==
// =======================
sf::Font &m_Canvas_GetFont(Canvas *canvas, std::string fontPath)
{
    std::string correctFilePath = GetExePath() + fontPath;
    if (canvas->fontCache.count(correctFilePath) == 0)
    {
        sf::Font font = sf::Font(correctFilePath);
        canvas->fontCache[correctFilePath] = font;
        return canvas->fontCache[correctFilePath];
    }
    else
    {
        return canvas->fontCache[correctFilePath];
    }
}

// =======================
// == Public Functions ==
// =======================
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

    return canvas;
}

void Canvas_Clear(Canvas *canvas)
{
    canvas->renderTexture->clear(sf::Color(0, 0, 0, 0));
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

void Canvas_DrawText(Canvas *canvas, int x, int y, std::string text, std::string fontPath, int fontSize, sf::Color color)
{
    sf::Font font = m_Canvas_GetFont(canvas, fontPath);

    sf::Text textBlock(font);
    textBlock.setString(text);
    textBlock.setCharacterSize(fontSize);
    textBlock.setFillColor(color);
    textBlock.setPosition({(float)x, (float)y});

    canvas->renderTexture->draw(textBlock);
}

void Canvas_DrawText(Canvas *canvas, int x, int y, int width, int height, std::string text, std::string fontPath, Alignment alignment, int fontSize, sf::Color color)
{
    sf::Font font = m_Canvas_GetFont(canvas, fontPath);

    sf::Text textBlock(font);
    textBlock.setString(text);
    textBlock.setCharacterSize(fontSize);
    textBlock.setFillColor(color);

    sf::FloatRect rect = textBlock.getLocalBounds();
    float posX, posY;
    if (alignment == Alignment::Left)
    {
        posX = x;
        posY = y + (height / 2) - (rect.size.y);
    }
    else if (alignment == Alignment::Center)
    {
        posX = x + (width / 2) - (rect.size.x / 2);
        posY = y + (height / 2) - (rect.size.y);
    }
    else
    {
        posX = x + width - rect.size.x;
        posY = y + (height / 2) - (rect.size.y);
    }
    
    sf::RenderTexture textContainer({(unsigned int)width, (unsigned int)height});
    textContainer.clear(sf::Color::Transparent);
    textContainer.draw(textBlock);
    textContainer.display();
    sf::Sprite textContainerSprite(textContainer.getTexture());
    
    textContainerSprite.setPosition({posX, posY});
    canvas->renderTexture->draw(textContainerSprite);
}

void Canvas_DrawSprite(Canvas *canvas, int x, int y, int width, int height, bool stretch, sf::Sprite *sprite, float opacity, float rotation, float scale)
{
    
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
    
    sf::Transform t2;
    // sprite->setOrigin({(float)width / 2, (float)height / 2});
    t2.translate({(float)x, (float)y});
    // sprite->setPosition({(float)x + width / 2, (float)y + height / 2});
    t2.scale({scale, scale}, {width / 2.f, height / 2.f});
    // sprite->scale({scale, scale});
    t2.rotate(sf::degrees(rotation), {width / 2.f, height / 2.f});
    sprite->setColor(sf::Color(255, 255, 255, opacity * 255));
    // sprite->setRotation(sf::degrees(rotation));
    // sprite->setOrigin({0.f, 0.f});
    canvas->renderTexture->draw(*sprite, t2);
}

void Canvas_DrawTexture(Canvas *canvas, int x, int y, sf::Texture *texture, float opacity, float rotation, float scale)
{
    sf::Sprite sprite = sf::Sprite(*texture);
    sf::Vector2u textureSize = texture->getSize();
    Canvas_DrawSprite(canvas, x, y, textureSize.x, textureSize.y, false, &sprite, opacity, rotation, scale);
}

void Canvas_DrawTexture(Canvas *canvas, int x, int y, int width, int height, bool stretch, sf::Texture *texture, float opacity, float rotation, float scale)
{
    sf::Sprite sprite = sf::Sprite(*texture);
    Canvas_DrawSprite(canvas, x, y, width, height, stretch, &sprite, opacity, rotation, scale);
}

void Canvas_DrawImage(Canvas *canvas, int x, int y, std::string filePath, float opacity, float rotation, float scale)
{
    Canvas_DrawImage(canvas, x, y, Alignment::Left, filePath, opacity, rotation, scale);
}
void Canvas_DrawImage(Canvas *canvas, int x, int y, Alignment alignment, std::string filePath, float opacity, float rotation, float scale)
{
    std::string correctFilePath = GetExePath() + filePath;
    if (canvas->textureCache.count(correctFilePath) == 0)
    {
        sf::Texture texture = sf::Texture(correctFilePath);

        int finalX = x;
        if (alignment == Alignment::Center)
        {
            finalX -= (texture.getSize().x / 2);
        }
        else if (alignment == Alignment::Right)
        {
            finalX -= (texture.getSize().x);
        }

        Canvas_DrawTexture(canvas, finalX, y, &texture, opacity, rotation, scale);
        canvas->textureCache[correctFilePath] = texture;
    }
    else
    {
        sf::Texture *texture = &canvas->textureCache[correctFilePath];

        int finalX = x;
        if (alignment == Alignment::Center)
        {
            finalX -= (texture->getSize().x / 2);
        }
        else if (alignment == Alignment::Right)
        {
            finalX -= (texture->getSize().x);
        }

        Canvas_DrawTexture(canvas, finalX, y, texture, opacity, rotation, scale);
    }
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