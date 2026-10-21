#pragma force_active on
struct Object {
    unsigned int padding[2];
    unsigned int flags;
};

extern "C" void fn_27_D32A8(Object* object) {
    object->flags &= ~0x00080000u;
}
