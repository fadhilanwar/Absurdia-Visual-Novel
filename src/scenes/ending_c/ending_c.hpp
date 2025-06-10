#pragma once

#include <SFML/Audio.hpp>
#include "../scene.hpp"
#include "../scene_32/scene_32.hpp"
#include "../../umum.hpp"

struct Ending_cData
{
    float animProgress;
};

Scene *Ending_c_Create();