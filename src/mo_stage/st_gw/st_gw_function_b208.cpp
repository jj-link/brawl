#pragma force_active on
struct Object {
    unsigned char padding[8];
    unsigned int flags;
};

extern "C" void fn_63_B208(Object* object) {
    object->flags &= ~0x00080000u;
}
