#pragma force_active on
extern "C" const float lbl_47_rodata_70;

struct Fn4749D0Obj {
    unsigned char pad[0x60];
    float x;
    float y;
    float z;
    unsigned char pad2[0x08];
    unsigned int state;
};

extern "C" void fn_47_49D0(Fn4749D0Obj* obj) {
    unsigned int s = obj->state;
    float zero = lbl_47_rodata_70;
    s = s & ~0x1Fu;
    obj->x = zero;
    obj->y = zero;
    obj->z = zero;
    obj->state = s;
}
