#include <nw4r/math/math_arithmetic.h>
#include <nw4r/math/math_types.h>
#include <orch_helpers.h>
#pragma force_active on

#pragma fp_contract off

struct Result {
    unsigned int flags;
    float scale[3];
    char padding[0x0c];
    float matrix[3][4];
};

class Class_80465F18 {
public:
    virtual void fn_8019B94C();
    virtual void fn_8019A670();
    virtual void fn_8019BA6C();
    virtual void fn_8019BA60();
    virtual void fn_8019BA30();
    virtual void fn_8019A0D4();
    virtual void fn_8019A15C();
    virtual void fn_8019A05C();
    virtual void fn_8019A1B0();
    virtual void fn_8019A238();
    virtual void fn_8019A28C();
    virtual void fn_8019A47C();
    virtual Result* fn_8019A874(Result*, int);

    char padding[0x10];
    unsigned short* nodeFlags;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual Result* slot12(Result*, int);

    char padding[0x10];
    unsigned short* nodeFlags;
};

struct BlendObject {
    char padding[0x18];
    int count;
    Class_80465F18** objects;
    float* weights;
};

struct QuaternionValue {
    float x, y, z, w;
};

extern const float lbl_805A32A8;
extern const float lbl_805A32AC;
extern const float lbl_805A32B0;

extern "C" {
unsigned int fn_8019DA84(BlendObject*, unsigned int);
float fn_80162188(float);
float fn_80162214(float);
void fn_80162774(float*);
void fn_80162894(float (*)[4]);
void fn_801EC934(float (*)[4], const QuaternionValue*);
void fn_801ED008(void*, const void*);
void fn_801ED0B0(const void*, const void*, void*);
void fn_801ED1EC(QuaternionValue*, const float (*)[4]);
void fn_801ED3B8(const QuaternionValue*, const QuaternionValue*,
                 QuaternionValue*, float);
}

extern "C" Result* fn_8019A874(BlendObject* self, Result* out, int index)
{
    float total = lbl_805A32A8;
    Class_80465F18* first = 0;
    int active = 0;

    for (int i = 0; i < self->count; ++i) {
        float weight = self->weights[i];
        Class_80465F18* object = self->objects[i];
        if (object && lbl_805A32A8 != weight &&
            !(object->nodeFlags[index] & 0xc000)) {
            total += weight;
            ++active;
            if (!first)
                first = object;
        }
    }

    if (active == 0) {
        out->flags = 0;
        return out;
    }
    if (active == 1)
        return first->fn_8019A874(out, index);

    unsigned int useQuaternion = fn_8019DA84(self, 8);
    unsigned int useLogScale = fn_8019DA84(self, 0x10);
    float invTotal = nw4r::math::FInv(total);
    float sx = lbl_805A32A8;
    float sy = sx;
    float sz = sx;
    float accumulatedWeight = sx;
    QuaternionValue rotation;
    rotation.x = sx;
    rotation.y = sx;
    rotation.z = sx;
    rotation.w = lbl_805A32AC;
    float fallback[9];
    out->flags = ~0u;
    out->scale[0] = sx;
    out->scale[1] = sx;
    out->scale[2] = sx;
    fn_80162894(out->matrix);

    for (int i = 0; i < self->count; ++i) {
        Class_80465F18* object = self->objects[i];
        float weight = self->weights[i];
        if (object && lbl_805A32A8 != weight &&
            !(object->nodeFlags[index] & 0xc000)) {
            Result temporary;
            Result* result = object->fn_8019A874(&temporary, index);
            float factor = weight * invTotal;
            unsigned int flags = result->flags;

            if (useLogScale) {
                if (!(flags & 8)) {
                    float x = result->scale[0] > lbl_805A32A8
                                  ? fn_80162214(result->scale[0])
                                  : lbl_805A32B0;
                    sx += factor * x;
                    float y = result->scale[1] > lbl_805A32A8
                                  ? fn_80162214(result->scale[1])
                                  : lbl_805A32B0;
                    sy += factor * y;
                    float z = result->scale[2] > lbl_805A32A8
                                  ? fn_80162214(result->scale[2])
                                  : lbl_805A32B0;
                    sz += factor * z;
                }
            } else if (!(flags & 8)) {
                out->scale[0] += result->scale[0] * factor;
                out->scale[1] += result->scale[1] * factor;
                out->scale[2] += result->scale[2] * factor;
            } else {
                out->scale[0] += factor;
                out->scale[1] += factor;
                out->scale[2] += factor;
            }

            if (useQuaternion) {
                QuaternionValue current;
                if (!(flags & 0x20)) {
                    fn_801ED1EC(&current, result->matrix);
                } else {
                    current.x = lbl_805A32A8;
                    current.y = lbl_805A32A8;
                    current.z = lbl_805A32A8;
                    current.w = lbl_805A32AC;
                }
                accumulatedWeight += weight;
                float t = nw4r::math::FInv(accumulatedWeight);
                fn_801ED3B8(&rotation, &current, &rotation, weight * t);
            } else if (!(flags & 0x20)) {
                if (i == 0) {
                    fallback[0] = result->matrix[0][0];
                    fallback[1] = result->matrix[0][1];
                    fallback[2] = result->matrix[0][2];
                    fallback[3] = result->matrix[1][0];
                    fallback[4] = result->matrix[1][1];
                    fallback[5] = result->matrix[1][2];
                    fallback[6] = result->matrix[2][0];
                    fallback[7] = result->matrix[2][1];
                    fallback[8] = result->matrix[2][2];
                }
                out->matrix[0][0] += result->matrix[0][0] * factor;
                out->matrix[0][1] += result->matrix[0][1] * factor;
                out->matrix[0][2] += result->matrix[0][2] * factor;
                out->matrix[1][0] += result->matrix[1][0] * factor;
                out->matrix[1][1] += result->matrix[1][1] * factor;
                out->matrix[1][2] += result->matrix[1][2] * factor;
            } else {
                if (i == 0)
                    fn_80162774(fallback);
                out->matrix[0][0] += factor;
                out->matrix[1][1] += factor;
            }

            if (!(flags & 0x40)) {
                out->matrix[0][3] += result->matrix[0][3] * factor;
                out->matrix[1][3] += result->matrix[1][3] * factor;
                out->matrix[2][3] += result->matrix[2][3] * factor;
            }
            out->flags &= flags;
        }
    }

    if (useLogScale) {
        out->scale[0] = fn_80162188(sx);
        out->scale[1] = fn_80162188(sy);
        out->scale[2] = fn_80162188(sz);
    }

    if (useQuaternion) {
        nw4r::math::VEC3 translation;
        translation.x = out->matrix[0][3];
        translation.y = out->matrix[1][3];
        translation.z = out->matrix[2][3];
        fn_801EC934(out->matrix, &rotation);
        out->matrix[0][3] = translation.x;
        out->matrix[1][3] = translation.y;
        out->matrix[2][3] = translation.z;
    } else {
        nw4r::math::VEC3* row0 =
            reinterpret_cast<nw4r::math::VEC3*>(&out->matrix[0][0]);
        nw4r::math::VEC3* row1 =
            reinterpret_cast<nw4r::math::VEC3*>(&out->matrix[1][0]);
        nw4r::math::VEC3* row2 =
            reinterpret_cast<nw4r::math::VEC3*>(&out->matrix[2][0]);
        fn_801ED0B0(row0, row1, row2);
        if (lbl_805A32A8 == nw4r::math::VEC3LenSq(row0) ||
            lbl_805A32A8 == nw4r::math::VEC3LenSq(row2)) {
            out->matrix[0][0] = fallback[0];
            out->matrix[0][1] = fallback[1];
            out->matrix[0][2] = fallback[2];
            out->matrix[1][0] = fallback[3];
            out->matrix[1][1] = fallback[4];
            out->matrix[1][2] = fallback[5];
            out->matrix[2][0] = fallback[6];
            out->matrix[2][1] = fallback[7];
            out->matrix[2][2] = fallback[8];
        } else {
            fn_801ED008(row0, row0);
            fn_801ED008(row2, row2);
            fn_801ED0B0(row2, row0, row1);
        }
    }

    out->flags &= 0x7fffffff;
    return out;
}
