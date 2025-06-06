#pragma once

#include <map>
#include <SFML/Graphics.hpp>

#include "../umum.hpp"

enum class Alignment
{
    Left,
    Center,
    Right
};

struct Canvas
{
    bool isRenderTextureFromExternal = false;
    sf::RenderTexture *renderTexture;

    std::map<std::string, sf::Font> fontCache;
    std::map<std::string, sf::Texture> textureCache;

    ~Canvas()
    {
        if (!isRenderTextureFromExternal)
            delete renderTexture;
    }
};

// Buat canvas (ngebuat RenderTexture SFML sendiri)
Canvas *Canvas_Create();
// Buat canvas dari RenderTexture SFML yang dikasih
Canvas *Canvas_Create(sf::RenderTexture *renderTexture);

// Hapus isi canvas
void Canvas_Clear(Canvas *canvas);
// Update isi canvas biar isinya bisa ditampilin
void Canvas_Update(Canvas *canvas);

// Gambar kotak
void Canvas_DrawRect(Canvas *canvas, int x, int y, int width, int height, sf::Color color);
// Gambar lingkaran
void Canvas_DrawCircle(Canvas *canvas, int x, int y, int radius, sf::Color color);

// Gambar teks
void Canvas_DrawText(Canvas *canvas, int x, int y, std::string text, std::string fontPath, int fontSize, sf::Color color);
// Kalau mau diatur ukuran teksnya, sama peletakan teksnya mau dimana (di parameter "alignment")
void Canvas_DrawText(Canvas *canvas, int x, int y, int width, int height, std::string text, std::string fontPath, Alignment alignment, int fontSize, sf::Color color);

// Gambar sprite SFML (pake DrawTexture/DrawImage aja, kecuali kalau memang butuh)
void Canvas_DrawSprite(Canvas *canvas, int x, int y, int width, int height, bool stretch, sf::Sprite *sprite, float opacity = 1.0, float rotation = 0.0, float scale = 1.0);

// Gambar texture SFML (pake DrawImage aja, kecuali kalau memang butuh)
void Canvas_DrawTexture(Canvas *canvas, int x, int y, sf::Texture *texture, float opacity = 1.0, float rotation = 0.0, float scale = 1.0);
void Canvas_DrawTexture(Canvas *canvas, int x, int y, int width, int height, bool stretch, sf::Texture *texture, float opacity = 1.0, float rotation = 0.0, float scale = 1.0);

// Gambar foto
void Canvas_DrawImage(Canvas *canvas, int x, int y, std::string filePath, float opacity = 1.0, float rotation = 0.0, float scale = 1.0);
// Kalau mau diatur peletakan fotonya, pake ini (atur di parameter "alignment")
void Canvas_DrawImage(Canvas *canvas, int x, int y, Alignment alignment, std::string filePath, float opacity = 1.0, float rotation = 0.0, float scale = 1.0);

// Copy isi canvas dari "srcCanvas" ke "targetCanvas"
void Canvas_Copy(Canvas *targetCanvas, Canvas *srcCanvas);
// Ambil isi canvas jadi texture SFML
sf::Texture Canvas_GetTexture(Canvas *canvas);