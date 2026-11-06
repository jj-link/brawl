#include <revolution/MTX/mtx.h>
#include <nw4r/math/math_types.h>
#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on

extern unsigned char lbl_804A7F40[];
extern unsigned char lbl_804A5514[];
extern Mtx lbl_8040AA88;
extern const float lbl_805A331C;
extern const float lbl_805A3320;
extern const float lbl_805A3324;
extern const float lbl_805A3328;
extern "C" void fn_801EC41C(const void*, void*);
extern "C" void fn_801EC1B8(const void*, const void*, void*);
extern "C" void fn_801EC184(const void*, void*);
extern "C" void fn_801B629C(const void*, void*);
extern "C" void fn_801B6280(const void*, void*);
extern "C" void fn_80162B40(const void*, const void*, void*);
extern "C" void fn_801ED008(const Vec*, Vec*);
extern "C" void fn_801ED0B0(const Vec*, const Vec*, Vec*);

struct CameraBank {
    unsigned short flags, index;
    Mtx inverse;
    Mtx cameras[32];
};
static inline void* camera(int id) {
    if (id < 32 && id >= 0)
        return ((CameraBank*)lbl_804A7F40)->cameras[id];
    return 0;
}
struct LightBank {
    unsigned char header[0x2C];
    unsigned char lights[128][0x44];
};
static inline void* light(int id) {
    if (id >= 0 && id < 128)
        return ((LightBank*)lbl_804A5514)->lights[id];
    return 0;
}
static inline void* inverse() {
    if (!(*(unsigned short*)lbl_804A7F40 & 1)) {
        fn_801EC41C(lbl_804A7F40 + *(unsigned short*)(lbl_804A7F40 + 2) * 0x30 + 0x34, lbl_804A7F40 + 4);
        *(unsigned short*)lbl_804A7F40 |= 1;
    }
    return lbl_804A7F40 + 4;
}
extern "C" void fn_8019E1D0(Mtx out, signed char cam, signed char lit) {
    if (out) {
        if (cam >= 0 && cam < 32) {
            void* c = camera(cam);
            void* inv = inverse();
            fn_801EC1B8(c, inv, out);
            out[0][3] = out[1][3] = out[2][3] = lbl_805A331C;
            fn_801EC1B8(lbl_804A7F40 + *(unsigned short*)(lbl_804A7F40 + 2) * 0x30 + 0x1434, out, out);
            return;
        }
        if (lit >= 0 && lit < 128 && (*(unsigned int*)light(lit) & 4)) {
            void* l = light(lit);
            nw4r::math::VEC3 dir, up, side, other;
            fn_801B629C(l, &dir);
            void* inv = inverse();
            bool positional = false;
            unsigned int flags = *(unsigned int*)l;
            if (!(flags & 1) && !(flags & 2))
                positional = true;
            if (positional || (lbl_805A331C == dir.x && lbl_805A331C == dir.y && lbl_805A331C == dir.z)) {
                fn_801B6280(l, &dir);
                fn_80162B40(&dir, inv, &dir);
                dir = -dir;
                if (lbl_805A331C == dir.x && lbl_805A331C == dir.y && lbl_805A331C == dir.z)
                    dir.y = lbl_805A3320;
            } else {
                fn_80162B40(&dir, inv, &dir);
            }
            fn_801ED008(dir, dir);
            if (nw4r::ut::Abs(dir.x) < lbl_805A3324 && nw4r::ut::Abs(dir.z) < lbl_805A3324) {
                up.x = up.y = lbl_805A331C;
                if (dir.y <= lbl_805A331C)
                    up.z = lbl_805A3320;
                else
                    up.z = lbl_805A3328;
            } else {
                up.x = up.z = lbl_805A331C;
                up.y = lbl_805A3328;
            }
            fn_801ED0B0(dir, up, side);
            fn_801ED008(side, side);
            fn_801ED0B0(side, dir, other);
            out[0][0] = side.x;
            out[0][1] = side.y;
            out[0][2] = side.z;
            out[1][0] = other.x;
            out[1][1] = other.y;
            out[1][2] = other.z;
            out[2][0] = -dir.x;
            out[2][1] = -dir.y;
            out[2][2] = -dir.z;
            fn_801EC1B8(out, inv, out);
            out[0][3] = out[1][3] = out[2][3] = lbl_805A331C;
            fn_801EC1B8(lbl_8040AA88, out, out);
            return;
        }
        fn_801EC184(lbl_804A7F40 + *(unsigned short*)(lbl_804A7F40 + 2) * 0x30 + 0x1434, out);
    }
}
