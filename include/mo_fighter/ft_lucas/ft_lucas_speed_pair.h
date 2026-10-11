#pragma once

#include <StaticAssert.h>
#include <types.h>

// Keep the register-returned vector as a POD, as in the neighboring fighter
// kinetic views, so forwarding its address does not introduce a Vec2f copy.
struct LucasSpeedPair {
    float x;
    float y;
};
static_assert(sizeof(LucasSpeedPair) == 8, "Speed return ABI mismatch");

extern "C" void* fn_114_C4D4(void* object, const LucasSpeedPair* speed, float third);
