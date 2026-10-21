#pragma force_active on
struct Object {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int flags : 2;
    unsigned int rest : 30;
};

extern "C" void fn_27_1A0060(Object* self, unsigned int value) {
    self->flags = value;
}
