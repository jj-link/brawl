#pragma force_active on
struct Vec3 {
    float x, y, z;
};

struct Matrix {
    float m[3][4];
};

struct ModelRef {
    void* model;
};

struct Object {
    char pad0[0x28];
    unsigned long index;
    char pad2C[0xC];
    ModelRef* ref;
    char pad3C[4];
    Vec3 position, rotation, scale;
};

extern "C" {
extern const float lbl_20_rodata_3A8;

int GetScnMtxPos__Q34nw4r3g3d12ScnMdlSimpleCFPQ34nw4r4math5MTX34Q44nw4r3g3d6ScnObj13ScnObjMtxTypeUl(
    const void*, Matrix*, int, unsigned long);

void getRotate__6MatrixFP5Vec3f(Matrix*, Vec3*);
void fn_8003E6DC(const Matrix*, Vec3*);

void fn_20_DA94(Object* self) {
    Matrix matrix;
    Vec3 position, rotation, scale;

    if (self->ref->model &&
        GetScnMtxPos__Q34nw4r3g3d12ScnMdlSimpleCFPQ34nw4r4math5MTX34Q44nw4r3g3d6ScnObj13ScnObjMtxTypeUl(
            self->ref->model, &matrix, 1, self->index + 1)) {
        float pz = matrix.m[2][3];
        float py = matrix.m[1][3];
        float px = matrix.m[0][3];
        position.y = py;
        position.x = px;
        position.z = pz;

        getRotate__6MatrixFP5Vec3f(&matrix, &rotation);
        fn_8003E6DC(&matrix, &scale);

        float factor = lbl_20_rodata_3A8;
        float x = rotation.x;
        float y = rotation.y;
        float z = rotation.z;
        float rx = factor * x;
        float ry = factor * y;
        float rz = factor * z;
        rotation.x = rx;
        rotation.y = ry;
        rotation.z = rz;

        self->position.x = position.x;
        self->position.y = position.y;
        self->position.z = position.z;
        self->rotation.x = rotation.x;
        self->rotation.y = rotation.y;
        self->rotation.z = rotation.z;
        self->scale.x = scale.x;
        self->scale.y = scale.y;
        self->scale.z = scale.z;
    }
}
}
