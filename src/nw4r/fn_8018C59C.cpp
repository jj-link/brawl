#include <revolution/GX.h>
#pragma force_active on

struct TexCoord { float u0, v0, u1, v1, u2, v2, u3, v3; };

extern "C" void fn_8018C59C(const float* pos, const float* size, int n, const TexCoord* tex, const unsigned int* col) {
    GXBegin(GX_QUADS, GX_VTXFMT0, 4);
    GXPosition2f32(pos[0], pos[1]);
    if (col) GXColor1u32(col[0]);
    for (int i = 0; i < n; i++) GXTexCoord2f32(tex[i].u0, tex[i].v0);

    GXPosition2f32(pos[0] + size[0], pos[1]);
    if (col) GXColor1u32(col[1]);
    for (int i = 0; i < n; i++) GXTexCoord2f32(tex[i].u1, tex[i].v1);

    GXPosition2f32(pos[0] + size[0], pos[1] + size[1]);
    if (col) GXColor1u32(col[3]);
    for (int i = 0; i < n; i++) GXTexCoord2f32(tex[i].u3, tex[i].v3);

    GXPosition2f32(pos[0], pos[1] + size[1]);
    if (col) GXColor1u32(col[2]);
    for (int i = 0; i < n; i++) GXTexCoord2f32(tex[i].u2, tex[i].v2);
}
