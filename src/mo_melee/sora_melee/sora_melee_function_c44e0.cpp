#pragma force_active on
struct Object {
    unsigned char padding[8];
    unsigned int flags;
};

extern "C" void fn_27_C44E0(Object* object) {
    object->flags &= ~0x2000u;
}
