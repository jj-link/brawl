#include <types.h>
#include <nw4r/math/math_types.h>

#pragma force_active on

using namespace nw4r::math;

extern "C" float fn_801622A0(float);
extern "C" void fn_80162B40(VEC3*, const void*, const VEC3*);

extern "C" float lbl_804A4408[6];
extern "C" float lbl_804A4420[3];
extern "C" const float lbl_805A303C;
extern "C" const float lbl_805A3048;
extern "C" const float lbl_805A304C;

struct Info {
    char pad[0xa6];
    u8 flags;
};

struct Owner {
    char pad[8];
    char mat[0x60];
    char mat2[0x30];
    VEC3 fallback;
};

inline float magnitude(float s) {
    if (s <= lbl_805A304C)
        return lbl_805A304C;
    return s * fn_801622A0(s);
}

inline VEC3& divBy(VEC3& v, float x) {
    return v *= (lbl_805A303C / x);
}

inline void copyVector(VEC3* out, float z, float y, float x) {
    out->x = x;
    out->y = y;
    out->z = z;
}

inline bool normalize(VEC3* v) {
    float s = VEC3Dot(v, v);
    if (s < lbl_805A3048)
        return false;
    divBy(*v, magnitude(s));
    return true;
}

extern "C" void fn_8017D628(VEC3* out, void* unused, const Info* info, Owner* owner) {
    switch (info->flags & 0x38) {
    case 8:
        fn_80162B40(out, owner->mat, (VEC3*)lbl_804A4408);
        fn_80162B40(out, owner->mat2, out);
        break;

    case 0:
    default:
        copyVector(out, owner->fallback.z, owner->fallback.y, owner->fallback.x);
        return;

    case 16:
        fn_80162B40(out, owner->mat, (VEC3*)lbl_804A4420);
        fn_80162B40(out, owner->mat2, out);
        break;

    case 24:
        VEC3 v(lbl_805A303C, lbl_805A303C, lbl_805A303C);
        fn_80162B40(out, owner->mat, &v);
        fn_80162B40(out, owner->mat2, out);
        break;
    }

    if (!normalize(out)) {
        copyVector(out, owner->fallback.z, owner->fallback.y, owner->fallback.x);
    }
}
