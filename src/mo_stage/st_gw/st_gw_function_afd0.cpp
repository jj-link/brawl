#pragma force_active on
struct Object {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int flags;
};

extern "C" void fn_63_AFD0(Object* object) {
    object->flags |= 0x02000000;
}
