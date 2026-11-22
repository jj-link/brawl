#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on
extern "C" float lbl_805A1E64;
extern "C" float lbl_805A1E68;
struct Vec { float x, y, z, w; };
struct Data { char pad[0x2C]; Vec current; Vec target; Vec residual; };
extern "C" void fn_8009F108(Data* p, float t) {
    float dx = p->target.x - p->current.x;
    float absdx = (float)(double)nw4r::ut::Abs(dx);
    float dy = p->target.y - p->current.y;
    float dz = p->target.z - p->current.z;
    float dw = p->target.w - p->current.w;
    float threshold = lbl_805A1E64 * t;
    float factor = lbl_805A1E68 * t;
    if (absdx > threshold) dx *= factor;
    if ((float)(double)nw4r::ut::Abs(dy) > threshold) dy *= factor;
    if ((float)(double)nw4r::ut::Abs(dz) > threshold) dz *= factor;
    if ((float)(double)nw4r::ut::Abs(dw) > threshold) dw *= factor;
    p->current.x += dx;
    p->current.y += dy;
    p->current.z += dz;
    p->current.w += dw;
    p->residual.x = p->target.x - p->current.x;
    p->residual.y = p->target.y - p->current.y;
    p->residual.z = p->target.z - p->current.z;
    p->residual.w = p->target.w - p->current.w;
}