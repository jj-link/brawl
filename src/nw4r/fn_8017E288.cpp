#include <nw4r/math/math_types.h>
#pragma force_active on

using namespace nw4r::math;

extern "C" {
extern const float lbl_805A3070, lbl_805A3074, lbl_805A3078;
extern const float lbl_805A307C, lbl_805A3080;

float fn_801622A0(float);
float fn_801622C4(float);
float fn_8016232C(float);
void fn_801ED0B0(const Vec*, const Vec*, Vec*);
void fn_801EC1B8(const MTX34*, const MTX34*, MTX34*);
void fn_801ECD70(MTX34*, int, void*);
}

inline float magnitude(float s) {
    if (s <= lbl_805A3074)
        return lbl_805A3074;
    return s * fn_801622A0(s);
}

inline float lengthSquared(const VEC3* v) {
    return VEC3Dot(v, v);
}

inline bool normalize(VEC3* v) {
    float s = lengthSquared(v);
    if (s < lbl_805A3070)
        return false;
    *v *= lbl_805A3078 / magnitude(s);
    return true;
}

extern "C" void fn_8017E288(
    void* unused, void* out, void* arg5, int flags, void* arg7,
    void (*callback)(Vec*, void*, void*), const VEC3* arg9, int arg10,
    int arg11, float angle, float value) {
    float s;
    Vec tmp, normal, first;
    MTX34 result;
    float origin[3];

    callback(&tmp, arg5, arg7);
    Vec* tmpPtr = &tmp;

    if (!(flags & 2))
        fn_801ED0B0(tmpPtr, (const Vec*)((char*)arg7 + 0xCC), &first);
    else
        fn_801ED0B0(tmpPtr, (const Vec*)((char*)arg5 + 0xC8), &first);

    if (!normalize((VEC3*)&first)) {
        first.x = *(float*)((char*)arg5 + 0xBC);
        first.y = *(float*)((char*)arg5 + 0xC0);
        first.z = *(float*)((char*)arg5 + 0xC4);
    }

    fn_801ED0B0(&first, tmpPtr, &normal);
    normalize((VEC3*)&normal);

    float nx = normal.x;
    float a23 = arg9->z;
    *(float*)((char*)arg7 + 0xCC) = nx;
    *(float*)((char*)arg7 + 0xD0) = normal.y;
    *(float*)((char*)arg7 + 0xD4) = normal.z;

    MTX34 basis;
    float a22 = normal.z, a21 = tmp.z, a20 = first.z;
    float a13 = arg9->y, a12 = normal.y, a11 = tmp.y, a10 = first.y;
    float a03 = arg9->x, a02 = normal.x, a01 = tmp.x, a00 = first.x;
    basis.m[0][1] = a01;
    basis.m[0][0] = a00;
    basis.m[0][2] = a02;
    basis.m[0][3] = a03;
    basis.m[1][0] = a10;
    basis.m[1][1] = a11;
    basis.m[1][2] = a12;
    basis.m[1][3] = a13;
    basis.m[2][0] = a20;
    basis.m[2][1] = a21;
    basis.m[2][2] = a22;
    basis.m[2][3] = a23;

    MTX34 rot;

    unsigned char* p = (unsigned char*)arg7;
    origin[0] = *(float*)(p + 0x40);
    origin[1] = *(float*)(p + 0x44);
    origin[2] = *(float*)(p + 0x48);

    if (p[0x9A])
        origin[0] += lbl_805A307C * p[0x9A];
    if (p[0x9B])
        origin[1] += lbl_805A307C * p[0x9B];
    if (p[0x9C])
        origin[2] += lbl_805A307C * p[0x9C];

    void* ptr = *(void**)(p + 0xC8);
    float yy = origin[1] + *(float*)((char*)ptr + 0x64);
    float xx = origin[0] + *(float*)((char*)ptr + 0x60);
    float zz = origin[2] + *(float*)((char*)ptr + 0x68);
    origin[1] = yy;
    origin[0] = xx;
    origin[2] = zz;

    float f6 = *(float*)((char*)arg7 + 0x30) *
               *(float*)((char*)arg7 + 0x38);
    float factor = f6 * *(float*)((char*)ptr + 0x58);
    s = factor * fn_8016232C(lbl_805A3080 * origin[1]);
    float c = factor * fn_801622C4(lbl_805A3080 * (float)(double)origin[1]);

    rot[0][0] = s;
    rot[0][1] = lbl_805A3074;
    rot[0][2] = -c;
    rot[0][3] = angle - s * angle;
    rot[1][0] = lbl_805A3074;
    rot[1][1] = lbl_805A3078;
    rot[1][2] = lbl_805A3074;
    rot[1][3] = lbl_805A3074;
    rot[2][0] = c;
    rot[2][1] = lbl_805A3074;
    rot[2][2] = s;
    rot[2][3] = -c * angle;

    fn_801EC1B8(&basis, &rot, &result);
    fn_801ECD70(&result, arg10, out);
    fn_801ECD70(&result, arg11, (char*)out + 0xC);
    *(float*)((char*)out + 0x18) = value;
}
