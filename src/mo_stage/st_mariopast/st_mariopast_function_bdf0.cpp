#pragma force_active on
struct Object {
    unsigned int padding[2];
    unsigned int flags;
};

extern "C" void fn_48_BDF0(Object* object) {
    object->flags &= ~0x2000U;
}
