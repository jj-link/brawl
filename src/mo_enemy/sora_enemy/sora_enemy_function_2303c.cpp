#include <mt/mt_vector.h>
#pragma force_active on

struct UnkObj {
    unsigned char pad[0x5C];
    void* field5C;
};
struct UnkPtr {
    unsigned char pad[0xC];
    float fieldC;
};

extern "C" {
extern const float lbl_41_rodata_D50[4];
void fn_8003DC64(Vec2f*, float, Vec2f*);

void fn_41_2303C(UnkObj* object) {
    const float* c = lbl_41_rodata_D50;
    UnkPtr* ptr = (UnkPtr*)object->field5C;
    if (ptr) {
        float f31 = ptr->fieldC * c[0];
        Vec2f local;
        local.m_x = c[1];
        local.m_y = c[2];
        fn_8003DC64(&local, c[3] * f31, (Vec2f*)((char*)object + 0x5c8));
        fn_8003DC64(&local, c[3] * (-f31), (Vec2f*)((char*)object + 0x5d0));
    }
}
}
