#pragma force_active on

struct Vec3f {
    float x, y, z;

    void set(float a, float b, float c) {
        x = a;
        y = b;
        z = c;
    }
};

struct Matrix {
    float m[3][4];
};

struct ModelList {
    unsigned char pad[0x44];
    void** entries;
};

extern "C" {
extern const float lbl_67_rodata_1C8[5];

int GetScnMtxPos__Q34nw4r3g3d12ScnMdlSimpleCFPQ34nw4r4math5MTX34Q44nw4r3g3d6ScnObj13ScnObjMtxTypeUl(
    const void*, Matrix*, int);

void mulPos__6MatrixFPC5Vec3fP5Vec3f(
    const Matrix*, const Vec3f*, Vec3f*);

void fn_67_CF90(ModelList* self, Vec3f* out, int index) {
    Matrix matrix;
    Vec3f pos, result;

    if (out) {
        float one = lbl_67_rodata_1C8[0];
        out->x = one;
        out->y = one;
        out->z = one;

        void* model = self->entries[index];
        if (model &&
            GetScnMtxPos__Q34nw4r3g3d12ScnMdlSimpleCFPQ34nw4r4math5MTX34Q44nw4r3g3d6ScnObj13ScnObjMtxTypeUl(
                model, &matrix, 1)) {
            pos.x = lbl_67_rodata_1C8[0];
            pos.y = lbl_67_rodata_1C8[0];
            pos.z = lbl_67_rodata_1C8[0];

            mulPos__6MatrixFPC5Vec3fP5Vec3f(&matrix, &pos, &result);
            out->set(result.x, result.y, result.z);
        }
    }
}
}
