#include <types.h>
#pragma force_active on

struct Matrix3x4 {
    float m[12];
};

struct Transform {
    float m[48];
};

struct Vector3 {
    float m[3];
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void* (*slot2(int))(void*);
    virtual void* (*slot3(int))(void*, void*);
    virtual void (*slot4(void*))(void*, void*, void*);
};

extern "C" {
void fn_8017A2FC(void*, void*, void*);
void* fn_80178868(void*);
void* fn_8017941C(int);
void fn_8017611C(Transform*, void*, void*);
void fn_80096690(Matrix3x4*);
Vector3* fn_80096694(Vector3*, float, float, float);
void fn_800966B0(Matrix3x4*, void*, Matrix3x4*);
void fn_8016DE48(void*, Matrix3x4*);
void* fn_801785A4(void*);
void fn_801F51DC(void*, int);
float fn_80179500(float);
void* fn_80179550(void*);
void* fn_80179558(void*, void*);
void fn_80179420(Vector3*, const Vector3*);
int fn_8017943C(Vector3*);
float fn_801794E0(const Vector3*, const Vector3*);
float fn_80179564(void*);
float fn_80179580(void*);
void fn_801795FC(void*, Vector3*);
void fn_80179644(Matrix3x4*, void*, unsigned char);
void fn_80179A38(Matrix3x4*, unsigned char, Matrix3x4*, float, float, float, float, float);
void fn_801750E8(void*, void*, void*, int, int, int);
void fn_801785A8(Vector3*, Vector3*, Vector3*, int);
void fn_80178564(Vector3*);
void fn_80178568(Vector3*, Matrix3x4*, void*);
void fn_801799F4(float*, float, float, float, float, float, float, float, float, float, float, float, float);
void fn_80179C40(Vector3*, Vector3*, Vector3*);
void fn_80162B40(Vector3*, Matrix3x4*, Vector3*);

extern float lbl_804A4408[6];
extern float lbl_804A442C[3];
extern float lbl_804A4438[12];
extern const float lbl_805A2FC0;
extern const float lbl_805A2FC4;
extern const float lbl_805A2FC8;
extern const float lbl_805A2FCC;
extern const float lbl_805A2FD0;
extern const double lbl_805A2FE0;
}

extern "C" void fn_80179C7C(Object_vptr_0* self, int arg1, void* arg2) {
    Vector3 point;
    Vector3 axis;
    Vector3 normal;
    Vector3 direction;
    Vector3 result;
    Vector3 offset;
    Vector3 vectorA;
    Vector3 vectorB;
    Vector3 vectorC;
    Vector3 vectorD;
    Vector3 vectorE;

    fn_8017A2FC(self, (void*)arg1, arg2);

    void* data = fn_80178868(*(void**)((char*)arg2 + 0x24));
    void* argument = fn_8017941C(arg1);
    Transform transform;
    fn_8017611C(&transform, argument, arg2);

    void (*callback)(void*, void*, void*) = self->slot4(arg2);

    Matrix3x4 matrix;
    Matrix3x4 position;
    fn_80096690(&matrix);
    fn_80096690(&position);
    fn_8016DE48(arg2, &position);
    fn_800966B0(&matrix, fn_8017941C(arg1), &position);
    fn_801F51DC(fn_801785A4(lbl_804A4438), 0);

    float scaleX = fn_80179500(
        matrix.m[0] * matrix.m[0] + matrix.m[4] * matrix.m[4] +
        matrix.m[8] * matrix.m[8]);
    float scaleY = fn_80179500(
        matrix.m[1] * matrix.m[1] + matrix.m[5] * matrix.m[5] +
        matrix.m[9] * matrix.m[9]);
    float scaleZ = fn_80179500(
        matrix.m[2] * matrix.m[2] + matrix.m[6] * matrix.m[6] +
        matrix.m[10] * matrix.m[10]);

    void* object = fn_80179550(arg2);
    while (object && ((float*)object)[51] > lbl_805A2FC8) {
        fn_80179420((Vector3*)((char*)object + 0xCC),
                    (Vector3*)lbl_804A442C);
        object = fn_80179558(arg2, object);
    }

    signed char value1 = *(signed char*)((char*)data + 0x9D);
    signed char value2 = *(signed char*)((char*)data + 0x9E);
    float ratio1 = (float)value1 / lbl_805A2FCC;
    float ratio2 = (float)value2 / lbl_805A2FCC;

    void* (*nextFn)(void*) = self->slot2(*(unsigned short*)data & 0x800);
    void* (*next)(void*, void*) = self->slot3(*(unsigned short*)data & 0x800);
    int first = 1;
    void* particle = nextFn(arg2);

    while (particle) {
        float value = fn_80179564(particle);
        if (!(value < lbl_805A2FC0)) {
            float duration = fn_80179580(particle);
            if (!(duration < lbl_805A2FC0)) {
                float adjustment = lbl_805A2FC8;
                if (*(unsigned char*)((char*)data + 0xA4)) {
                    fn_80178564(&point);
                    fn_801795FC(particle, &point);
                    adjustment += lbl_805A2FD0 *
                                  fn_80179500(fn_801794E0(&point, &point)) /
                                  duration;
                }

                fn_801750E8(self, particle, data, arg1, first, 0);
                first = 0;

                Matrix3x4 shape;
                Matrix3x4 parameters;
                fn_80179644(&shape, particle,
                            *(unsigned char*)((char*)data + 0xA3));
                fn_80179A38(&parameters,
                            *(unsigned char*)((char*)data + 0xA5),
                            &shape, ratio1, ratio2, value, duration, adjustment);

                fn_80178564(&axis);
                fn_80178564(&normal);
                fn_80178564(&direction);
                fn_80178564(&result);
                callback(&result, &transform, particle);
                fn_80162B40(&result, &matrix, &result);
                fn_80179420(&normal, &result);
                fn_8017943C(&normal);

                Vector3 side;
                fn_80179420(&axis, fn_80096694(
                    &side, result.m[1], -result.m[0], lbl_805A2FC4));

                if (fn_8017943C(&axis)) {
                    Vector3 plane;
                    fn_80179420(&direction, fn_80096694(
                        &plane,
                        -result.m[0] * result.m[2],
                        -result.m[1] * result.m[2],
                        result.m[0] * result.m[0] +
                            result.m[1] * result.m[1]));
                } else {
                    fn_80179C40(&axis, &result,
                                (Vector3*)((char*)particle + 0xCC));
                    if (!fn_8017943C(&axis))
                        fn_80179420(&axis, (Vector3*)lbl_804A4408);
                    fn_80179C40(&direction, &axis, &result);
                }

                fn_8017943C(&direction);
                fn_80179420((Vector3*)((char*)particle + 0xCC), &direction);

                fn_80178564(&offset);
                fn_80178568(&offset, &matrix,
                            (void*)((char*)particle + 0xAC));

                Matrix3x4 output;
                fn_801799F4(
                    output.m,
                    scaleX * axis.m[0], scaleY * normal.m[0],
                    scaleZ * direction.m[0], offset.m[0],
                    scaleX * axis.m[1], scaleY * normal.m[1],
                    scaleZ * direction.m[1], offset.m[1],
                    scaleX * axis.m[2], scaleY * normal.m[2],
                    scaleZ * direction.m[2], offset.m[2]);

                Matrix3x4 resultMatrix;
                fn_80096690(&resultMatrix);
                fn_800966B0(&resultMatrix, &output, &parameters);

                fn_80096694(&vectorA, resultMatrix.m[3], resultMatrix.m[7],
                            resultMatrix.m[11]);
                fn_80096694(&vectorB,
                            resultMatrix.m[0] + resultMatrix.m[1],
                            resultMatrix.m[4] + resultMatrix.m[5],
                            resultMatrix.m[8] + resultMatrix.m[9]);
                fn_80096694(&vectorC,
                            resultMatrix.m[0] - resultMatrix.m[1],
                            resultMatrix.m[4] - resultMatrix.m[5],
                            resultMatrix.m[8] - resultMatrix.m[9]);
                fn_801785A8(&vectorA, &vectorB, &vectorC,
                            *(unsigned char*)((char*)self + 0xAE) != 0);

                if (*(unsigned char*)((char*)data + 0xA1) == 1) {
                    fn_80096694(&vectorD,
                                resultMatrix.m[1] + resultMatrix.m[2],
                                resultMatrix.m[5] + resultMatrix.m[6],
                                resultMatrix.m[9] + resultMatrix.m[10]);
                    fn_80096694(&vectorE,
                                resultMatrix.m[1] - resultMatrix.m[2],
                                resultMatrix.m[5] - resultMatrix.m[6],
                                resultMatrix.m[9] - resultMatrix.m[10]);
                    fn_801785A8(&vectorA, &vectorD, &vectorE,
                                *(unsigned char*)((char*)self + 0xAE) != 0);
                }
            }
        }
        particle = next(arg2, particle);
    }
}
