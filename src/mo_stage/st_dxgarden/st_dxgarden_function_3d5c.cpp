#pragma force_active on
struct Object {
    unsigned char padding[8];
    unsigned int flags;
};

extern "C" void fn_77_3D5C(Object* object) {
    object->flags |= 0x00080000u;
}
