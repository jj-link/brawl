#include <types.h>
#pragma force_active on
struct Obj {
    unsigned char pad[0x7C];
    float start, end;
    int duration, elapsed;
    float value() {
        if (elapsed >= duration) return end;
        return start + ((float)elapsed * (end - start)) / (float)duration;
    }
};
extern "C" void fn_801BD368(Obj* p, int n, float v) {
    float clamped;
    if (v > 1.0f) clamped = 1.0f;
    else if (v < 0.0f) clamped = 0.0f;
    else clamped = v;
    p->start = p->value();
    p->end = clamped;
    p->duration = n;
    p->elapsed = 0;
}