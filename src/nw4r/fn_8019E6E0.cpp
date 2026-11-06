#include <revolution/MTX/mtx.h>
#include <nw4r/math/math_types.h>
#include <nw4r/ut/ut_algorithm.h>

#pragma force_active on

extern unsigned char lbl_804A7F40[];
extern unsigned char lbl_804A5514[];
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
extern "C" void fn_801ED0EC(const Vec*, const Vec*, Vec*);

struct CameraBank {
    unsigned short flags, index;
    Mtx inverse;
    Mtx cameras[32];
};

struct LightBank {
    unsigned char header[0x2C];
    unsigned char lights[128][0x44];
};

static inline void* camera(int id) {
    if (id < 32 && id >= 0)
        return ((CameraBank*)lbl_804A7F40)->cameras[id];
    return 0;
}

static inline void* light(int id) {
    if (id >= 0 && id < 128)
        return ((LightBank*)lbl_804A5514)->lights[id];
    return 0;
}

static inline void* inverse(Mtx* current) {
    if (!(*(unsigned short*)lbl_804A7F40 & 1)) {
        fn_801EC41C(current, lbl_804A7F40 + 4);
        *(unsigned short*)lbl_804A7F40 |= 1;
    }
    return lbl_804A7F40 + 4;
}

extern "C" void fn_8019E6E0(Mtx out, signed char cam, signed char lit) {
    if (out) {
        Mtx* current = (Mtx*)(lbl_804A7F40 + 4 +
            ((CameraBank*)lbl_804A7F40)->index * sizeof(Mtx)) + 1;
        nw4r::math::VEC3 other, up, forward, dir;

        forward.x = -(*current)[2][0];
        forward.y = -(*current)[2][1];
        forward.z = -(*current)[2][2];

        void* inv = inverse(current);

        if (lit >= 0 && lit < 128 && (*(unsigned int*)light(lit) & 4)) {
            void* l = light(lit);
            fn_801B629C(l, &dir);

            bool positional = false;
            unsigned int flags = *(unsigned int*)l;
            if (!(flags & 1) && !(flags & 2))
                positional = true;

            if (positional ||
                (lbl_805A331C == dir.x && lbl_805A331C == dir.y &&
                 lbl_805A331C == dir.z)) {
                fn_801B6280(l, &dir);
                fn_80162B40(&dir, inv, &dir);
                dir = -dir;
                if (lbl_805A331C == dir.x && lbl_805A331C == dir.y &&
                    lbl_805A331C == dir.z)
                    dir.y = lbl_805A3320;
            } else {
                fn_80162B40(&dir, inv, &dir);
            }

            if (!(*(unsigned int*)l & 2))
                fn_801ED0EC(forward, dir, other);
            else
                other = -dir;

            if (nw4r::ut::Abs(other.x) < lbl_805A3324 &&
                nw4r::ut::Abs(other.z) < lbl_805A3324) {
                up.x = up.y = lbl_805A331C;
                if (other.y <= lbl_805A331C)
                    up.z = lbl_805A3320;
                else
                    up.z = lbl_805A3328;
            } else {
                up.x = up.z = lbl_805A331C;
                up.y = lbl_805A3328;
            }
        } else if (cam >= 0 && cam < 32) {
            float (*c)[4] = (float (*)[4])camera(cam);
            up.x = c[1][0];
            up.y = c[1][1];
            up.z = c[1][2];
            nw4r::math::VEC3 v(-c[2][0], -c[2][1], -c[2][2]);
            fn_801ED0EC(forward, v, other);
        } else {
            fn_801EC184(
                lbl_804A7F40 + *(unsigned short*)(lbl_804A7F40 + 2) * 0x30 + 0x1434,
                out);
            return;
        }

        nw4r::math::VEC3 side, result;
        fn_801ED008(other, other);
        fn_801ED0B0(up, other, side);
        fn_801ED008(side, side);
        fn_801ED0B0(other, side, result);

        out[0][0] = side.x;
        out[0][1] = side.y;
        out[0][2] = side.z;
        out[1][0] = result.x;
        out[1][1] = result.y;
        out[1][2] = result.z;
        out[2][0] = other.x;
        out[2][1] = other.y;
        out[2][2] = other.z;

        fn_801EC1B8(out, inv, out);
        out[0][3] = out[1][3] = out[2][3] = lbl_805A331C;
        fn_801EC1B8(
            lbl_804A7F40 + *(unsigned short*)(lbl_804A7F40 + 2) * 0x30 + 0x1434,
            out, out);
    }
}
