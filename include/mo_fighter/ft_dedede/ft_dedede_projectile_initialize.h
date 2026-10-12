#pragma once

struct DededeInitializeObject;
class Vec3f;

// The projectile's private storage view is intentionally incomplete here.
// The final argument follows the original full-width zero/nonzero test.
extern "C" void fn_117_1F2EC(DededeInitializeObject* article,
    unsigned int taskId, unsigned int resourceId, int parameter,
    const Vec3f* position, float facing, int kind, int thrown);
