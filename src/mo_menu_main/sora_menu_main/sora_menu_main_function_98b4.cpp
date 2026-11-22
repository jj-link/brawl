#include <mu/mu_object.h>
#pragma force_active on

struct Matrix {
    float m[3][4];
};

struct Entry {
    unsigned char flags;
    char pad[3];
    int id;
    float x, z;
    int tail;
};

struct Self {
    char pad[0x4c];
    Entry entries[8];
};

struct PosEntry {
    char pad[12];
    float x, z;
};

struct PosSelf {
    char pad[0x48];
    PosEntry entries[8];
};

struct Flags {
    unsigned char active : 1;
    unsigned char rest : 7;
};

extern "C" {
extern const float lbl_2_rodata_218[];
void fn_1_6D74(void*, void*);
void fn_1_6D60(void*, void*);
void fn_800B6838(void*, const Vec3f*);
Matrix fn_2_A618(void*, int);
void fn_8003E6DC(const Matrix*, Vec3f*);
void fn_800B6E08(void*, const Vec3f*);
}

static inline Vec3f position(void* object) {
    Vec3f v;
    v = *(Vec3f*)((char*)object + 0x3c);
    return v;
}

static inline void getScale(void* obj, int index, Vec3f* scale) {
    Matrix matrix = fn_2_A618(obj, index);
    fn_8003E6DC(&matrix, scale);
}

static inline float multiply(float a, float b) { return b * a; }

extern "C" void fn_2_98B4(void* obj, int index, bool flag) {
    const float* constants = lbl_2_rodata_218;
    void* model;
    int offset = index * 0x14;
    Entry* entry = &((Self*)obj)->entries[index];

    float frame = ((Flags*)&entry->flags)->active
        ? constants[0x144 / 4]
        : constants[0x88 / 4];
    if (flag) {
        frame += constants[0x138 / 4];
    }

    (*(MuObject**)((char*)obj + (index + 0xd) * 4 + 0xe8))
        ->setFrameVisible(frame);

    model = *(void**)((char*)obj + 0x12c);
    fn_1_6D74(*(void**)((char*)obj + 0x40), *(void**)((char*)model + 0x10));

    if (flag && ((Flags*)&entry->flags)->active) {
        fn_1_6D60(*(void**)((char*)obj + 0x40), *(void**)((char*)model + 0x10));

        Vec3f translation;
        Vec3f newScale;
        Vec3f oldPosition;
        Vec3f scale;
        float x = ((PosSelf*)obj)->entries[index].x;
        float z = ((PosSelf*)obj)->entries[index].z;
        oldPosition = *(Vec3f*)((char*)*(void**)((char*)obj + (index + 4) * 4 + 0xe8) + 0x3c);
        translation.m_x = x;
        translation.m_y = oldPosition.m_y;
        translation.m_z = z;
        fn_800B6838(model, &translation);

        getScale(obj, index, &scale);
        char* entries = **(char***)((char*)obj + 0xd8);
        int selected = ((Flags*)&entry->flags)->active
            ? *(int*)((char*)obj + offset + 0x50)
            : -1;
        float result = multiply(scale.m_x, *(float*)(entries + selected * 0x60 + 0x38));

        newScale.m_x = result;
        newScale.m_y = constants[0x138 / 4];
        newScale.m_z = result;
        fn_800B6E08(model, &newScale);
    }
}
