#pragma force_active on
struct Object {
    unsigned int padding[2];
    unsigned int flags;
};

extern "C" void fn_27_C991C(Object* object) {
    object->flags &= ~0x00400000u;
}
