#pragma force_active on
struct Object {
    unsigned int padding[2];
    unsigned int flags;
};

extern "C" void fn_63_B130(Object* object) {
    object->flags |= 0x00080000;
}
