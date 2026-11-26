#include <types.h>
#include <nw4r/math/math_types.h>
#include <mt/mt_vector.h>
#include <revolution/GX.h>

#pragma force_active on

extern "C" {
void* getManager__15gfCameraManagerFv();
void fn_801ED008(const Vec3f*, Vec3f*);
void fn_801ED0B0(const Vec3f*, const Vec3f*, Vec3f*);
void fn_801EC934(void*, const float*);
void fn_801EC1B8(const void*, const void*, void*);
void fn_801EC8DC(const void*, void*, float, float, float);
void fn_80162974(void*, const float*, float);
void fn_801F302C(void*, int);
void fn_801F2FB0(void*, int);
void fn_801F51DC(const void*, int);
void fn_801F52E4(int);
double fn_804005AC(float);

extern const float lbl_90_rodata_0;
extern const float lbl_90_rodata_C;
extern const float lbl_90_rodata_10;
extern const float lbl_90_rodata_40;
extern const float lbl_90_rodata_44;
extern const float lbl_90_rodata_48;
extern const float lbl_90_rodata_6C;
extern const float lbl_90_rodata_104;
extern const float lbl_90_rodata_118;
}

struct Matrix34Copy {
    u32 words[12];
};

static inline float dot(const Vec3f& a, const Vec3f& b) {
    return nw4r::math::VEC3Dot(
        (const nw4r::math::VEC3*)&a,
        (const nw4r::math::VEC3*)&b);
}

static inline float lengthSq(const Vec3f& a) {
    return nw4r::math::VEC3LenSq((const nw4r::math::VEC3*)&a);
}

extern "C" void fn_90_5D00(void* object) {
    char* self = (char*)object;
    char* entries = self + 0x284;
    int x0;
    int x1;
    int y0;
    int y1;
    u32 color;
    int bit;
    u32 bits;
    int baseIndex;
    int word;
    u32* masks;
    s32 count = *(s32*)(self + 0x6AC4);
    void* state0;
    void* state1;
    state1 = self + 0x6AE8;
    state0 = self + 0x6AC8;

    if (count > 0) {
        Matrix34Copy model;
        Matrix34Copy cameraCopy = *(Matrix34Copy*)getManager__15gfCameraManagerFv();
        Matrix34Copy rotation;
        Matrix34Copy cameraMatrix = cameraCopy;

        Vec3f camera;
        Vec3f initial;
        Vec3f scaled;
        Vec3f alternate;
        Vec3f cross;
        Vec3f axis;
        Vec3f b;
        Vec3f a;
        Vec3f scale;
        float zAxis[3];
        float quaternion[4];

        camera = *(Vec3f*)((char*)getManager__15gfCameraManagerFv() + 0x78);
        initial.m_x = lbl_90_rodata_0;
        initial.m_y = lbl_90_rodata_0;
        initial.m_z = lbl_90_rodata_40;

        fn_801ED008(&initial, &a);
        fn_801ED008(&camera, &b);

        float t = lbl_90_rodata_44 + lbl_90_rodata_44 * dot(a, b);
        if (t <= lbl_90_rodata_0) {
            axis.m_x = lbl_90_rodata_10;
            axis.m_y = lbl_90_rodata_0;
            axis.m_z = lbl_90_rodata_0;
            fn_801ED0B0(&a, &axis, &axis);

            if (lengthSq(axis) <= lbl_90_rodata_48) {
                alternate.m_x = lbl_90_rodata_0;
                alternate.m_y = lbl_90_rodata_10;
                alternate.m_z = lbl_90_rodata_0;
                axis = alternate;
                fn_801ED0B0(&a, &axis, &axis);
            }

            quaternion[0] = axis.m_x;
            quaternion[1] = axis.m_y;
            quaternion[2] = axis.m_z;
            quaternion[3] = lbl_90_rodata_0;
        }

        float s = rsqrtf(t);
        fn_801ED0B0(&a, &b, &cross);
        nw4r::math::VEC3Scale(
            (nw4r::math::VEC3*)&scaled,
            (const nw4r::math::VEC3*)&cross,
            s);
        cross = scaled;

        quaternion[0] = cross.m_x;
        quaternion[1] = cross.m_y;
        quaternion[2] = cross.m_z;
        quaternion[3] = lbl_90_rodata_C * (s * t);

        fn_801EC934(&rotation, quaternion);
        fn_801F302C(state1, 0);
        fn_801F2FB0(state0, 0);

        float frameScale;
        float angleScale;
        float alphaScale;
        float two;
        float one;
        float zero;
        zero = lbl_90_rodata_0;
        zAxis[0] = zero;
        zAxis[1] = zero;
        zAxis[2] = lbl_90_rodata_10;
        one = zAxis[2];
        two = lbl_90_rodata_44;
        alphaScale = lbl_90_rodata_118;
        angleScale = lbl_90_rodata_104;
        frameScale = lbl_90_rodata_6C;

        masks = (u32*)entries;
        word = 0;
        baseIndex = 0;

        for (; word < 16; word++, masks++, baseIndex += 32) {
            bits = *masks;
            if (bits != 0) {
                for (bit = 0; bit < 32 && bits != 0; bit++) {
                    if (bits & 1) {
                        char* entry = entries + (baseIndex + bit) * 0x34;
                        float alpha = two *
                            (*(float*)(entry + 0x40) / *(float*)(entry + 0x44)) - one;

                        if (alpha <= zero) {
                            color = 0xFFFFFFFF;
                        } else {
                            if (alpha > one) {
                                alpha = one;
                            }
                            color = (u32)(alphaScale * (one - alpha)) | 0xFFFFFF00;
                        }

                        fn_80162974(&model, zAxis, angleScale * *(float*)(entry + 0x54));

                        scale.m_z = scale.m_y = scale.m_x = *(float*)(entry + 0x70);
                        fn_801EC8DC(&model, &model, scale.m_x, scale.m_y, scale.m_z);
                        fn_801EC1B8(&model, &rotation, &model);

                        ((float*)&model)[3] = *(float*)(entry + 0x48);
                        ((float*)&model)[7] = *(float*)(entry + 0x4C);
                        ((float*)&model)[11] = *(float*)(entry + 0x50);
                        fn_801EC1B8(&cameraMatrix, &model, &model);
                        fn_801F51DC(&model, 0);
                        fn_801F52E4(0);

                        t = *(float*)(entry + 0x58);
                        int index = (int)(frameScale * (t - (float)fn_804005AC(t)));
                        x0 = (index % 12) * 0x500;
                        y0 = (index / 12) * 0x500;
                        x1 = x0 + 0x500;
                        y1 = y0 + 0x500;

                        GXBegin(GX_QUADS, GX_VTXFMT0, 4);
                        GXPosition3s16(-24, 24, 0);
                        count--;
                        GXColor1u32(color);
                        GXTexCoord2s16(x0, y0);

                        GXPosition3s16(24, 24, 0);
                        GXColor1u32(color);
                        GXTexCoord2s16(x1, y0);

                        GXPosition3s16(24, -24, 0);
                        GXColor1u32(color);
                        GXTexCoord2s16(x1, y1);

                        GXPosition3s16(-24, -24, 0);
                        GXColor1u32(color);
                        GXTexCoord2s16(x0, y1);

                        if (count <= 0) {
                            return;
                        }
                    }
                    bits >>= 1;
                }
            }
        }
    }
}
