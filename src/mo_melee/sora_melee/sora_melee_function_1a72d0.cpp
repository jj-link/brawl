#pragma force_active on
struct Object {
    unsigned int padding[2];
    unsigned int flags;
};

extern "C" void fn_27_1A72D0(Object* object) {
    object->flags &= ~0x00080000u;
}
