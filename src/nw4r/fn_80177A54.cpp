#pragma force_active on
#include <nw4r/math/math_types.h>

struct Target {
    char pad0[0x0C];
    float x;
    char pad1[0x0C];
    float y;
    char pad2[0x0C];
    float z;
};

struct Source {
    char pad[0x20];
    void* field20;
};

struct Result {
    float value;
    char pad[24];
};

extern "C" {
float fn_801F519C(float*);
void fn_80166B8C(void*, void*);
void fn_801ECD70(void*, void*, void*);
float fn_801622A0(float);

extern float lbl_805A2F94;
extern float lbl_805A2F98;
extern float lbl_805A2F9C;
}

inline nw4r::math::VEC3& divBy(nw4r::math::VEC3& v, float x) {
    return v *= (lbl_805A2F98 / x);
}

inline bool normalize(nw4r::math::VEC3* v) {
    float lenSq = nw4r::math::VEC3Dot(v, v);
    if (lenSq < lbl_805A2F9C) {
        return false;
    }

    float denom;
    if (lenSq <= lbl_805A2F94) {
        denom = lbl_805A2F94;
    } else {
        denom = lenSq * fn_801622A0(lenSq);
    }
    divBy(*v, denom);
    return true;
}

extern "C" void fn_80177A54(void*, Target* target, Source* source, void* arg3, float scale) {
    Result modeValue;
    fn_801F519C(&modeValue.value);
    int mode = (int)modeValue.value;

    switch (mode) {
    case 0: {
        float matrix[12];
        fn_80166B8C(source->field20, matrix);
        nw4r::math::VEC3 vec(matrix[3], matrix[7], matrix[11]);
        fn_801ECD70(arg3, &vec, &vec);

        if (normalize(&vec)) {
            if (vec.z >= lbl_805A2F94) {
                target->x += vec.x * scale;
                target->y += vec.y * scale;
                target->z += vec.z * scale;
            } else {
                target->x -= vec.x * scale;
                target->y -= vec.y * scale;
                target->z -= vec.z * scale;
            }
        }
        break;
    }
    case 1:
        target->z += scale;
        break;
    }
}
