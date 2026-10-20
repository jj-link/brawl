#pragma force_active on
struct Vec3 {
    float x, y, z;
};

struct Flags {
    unsigned char active : 1;
    unsigned char rest : 7;
};

struct Matrix {
    float m[3][4];
};

extern "C" {
extern const float lbl_2_rodata_218[];
Matrix fn_2_A618(void*);
void fn_8003E6DC(const Matrix*, Vec3*);
int fn_2_B048(void*, float*, float*, float*, float*);
int fn_2_AC10(void*, Vec3*, int, float, float);
}

extern "C" int fn_2_A420(void* object, float* result, int index, float value) {
    const float* constants = lbl_2_rodata_218;
    Vec3 position;
    Matrix matrix = fn_2_A618(object);
    Vec3 scale;
    fn_8003E6DC(&matrix, &scale);

    char* entries = **(char***)((char*)object + 0xd8);
    char* entry = (char*)object + index * 0x14;
    int selected = ((Flags*)(entry + 0x4c))->active
        ? *(int*)(entry + 0x50)
        : -1;

    float scaleX = scale.x;
    float width = *(float*)(entries + selected * 0x60 + 0x38);
    float step = constants[0x154 / 4] * (width * scaleX);

    float left, top, right, bottom;
    if (fn_2_B048(object, &left, &top, &right, &bottom) == 0) {
        left = constants[0x15c / 4];
        right = constants[0x160 / 4];
    }

    float distance = constants[0x88 / 4];
    for (; distance < right - step; distance += step) {
        if (fn_2_AC10(object, &position, index, distance, value) == 0) {
            *result = distance;
            return 1;
        }
        if (distance > constants[0x88 / 4]) {
            if (fn_2_AC10(object, &position, index, -distance, value) == 0) {
                *result = -distance;
                return 1;
            }
        }
    }
    return 0;
}
