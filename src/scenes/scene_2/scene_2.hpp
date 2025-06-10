#pragma once

#include <SFML/Audio.hpp>

#include "../scene.hpp"
#include "../scene_3/scene_3.hpp"
#include "../../umum.hpp"

struct Scene2Data
{
    float part = 1.f;

    float animProgress;
    float animProgressPart;
};

Scene *Scene2_Create();
