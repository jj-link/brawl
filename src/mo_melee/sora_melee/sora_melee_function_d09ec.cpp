#pragma force_active on
struct Object {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int flags;
};

extern "C" void fn_27_D09EC(Object* object) {
    object->flags &= ~0x400u;
}
