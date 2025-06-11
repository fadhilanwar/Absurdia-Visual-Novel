#pragma once

#include <SFML/Audio.hpp>

#include "../scene.hpp"
#include "../scene_3/scene_3.hpp"
#include "../../umum.hpp"

struct Scene2Data
{
    float part = 1.f;
    bool hasChangedToKereta;

    float animProgress;
    float animProgressPart;

    bool soundPlayedPart2;
};

Scene *Scene2_Create();
