#pragma force_active on
struct Data {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int flags : 4;
    unsigned int rest : 28;
};

extern "C" void fn_27_199364(Data* self, unsigned int value) {
    self->flags = value;
}
