#pragma force_active on
struct Object {
    unsigned int unknown[2];
    unsigned int flags;
};

extern "C" void fn_27_1D0914(Object* object) {
    object->flags &= ~0x00080000u;
}
