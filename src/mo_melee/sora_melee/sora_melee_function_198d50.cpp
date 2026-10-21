#pragma force_active on
struct Object {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int flags;
};

extern "C" void fn_27_198D50(Object* object) {
    object->flags &= ~0x00400000u;
}
