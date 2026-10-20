#pragma force_active on
#pragma optimization_level 1

typedef unsigned int u32;

struct Object {
    unsigned char padding[0x114];
    void* target;
};

extern "C" {
extern const float lbl_27_rodata_10B4;
extern const float lbl_27_rodata_10B8;

int fn_27_8CE54(void* self, u32 a, u32 b, float x, float y);

int fn_27_13FF7C(Object* self, u32 a, u32 b) {
    if (self->target) {
        return fn_27_8CE54(self->target, a, b,
                          lbl_27_rodata_10B4, lbl_27_rodata_10B8);
    }
    return 0;
}
}
