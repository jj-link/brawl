#include <revolution/GX/GXGeometry.h>
#include <revolution/GX/GXVert.h>
#include <nw4r/math/math_types.h>
#include <types.h>
#pragma force_active on

using nw4r::math::VEC3;

extern const double lbl_805A3040;
extern const float lbl_805A303C;

struct Ring {
    VEC3 center;  // 0x00
    VEC3 axisB;   // 0x0C
    VEC3 axisA;   // 0x18
    f32 v;        // 0x24
};

inline void emitPosition(const VEC3& p) { GXPosition3f32(p.x, p.y, p.z); }

extern "C" void fn_8017C0F0(void* cls, const Ring* b, const Ring* a, u32 flags, s32 count, const f32* table) {
    f32 invN = lbl_805A303C / (f32)count;
    GXBegin(GX_TRIANGLESTRIP, GX_VTXFMT0, (u16)(count * 2 + 2));
    if (flags & 4) {
        for (s32 i = 0; i <= count; i++) {
            f32 c = table[0];
            f32 s = table[1];
            {
                emitPosition((b->axisB * s + b->axisA * c) + b->center);
            }
            if (flags & 1) {
                GXTexCoord2f32(invN * (f32)i, b->v);
            }
            {
                emitPosition((a->axisB * s + a->axisA * c) + a->center);
            }
            if (flags & 1) {
                GXTexCoord2f32(invN * (f32)i, a->v);
            }
            table += 2;
        }
    } else {
        for (s32 i = 0; i <= count; i++) {
            f32 c = table[0];
            f32 s = table[1];
            {
                emitPosition((a->axisB * s + a->axisA * c) + a->center);
            }
            if (flags & 1) {
                GXTexCoord2f32(invN * (f32)i, a->v);
            }
            {
                emitPosition((b->axisB * s + b->axisA * c) + b->center);
            }
            if (flags & 1) {
                GXTexCoord2f32(invN * (f32)i, b->v);
            }
            table += 2;
        }
    }
}
