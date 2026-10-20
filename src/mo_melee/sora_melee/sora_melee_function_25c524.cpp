#pragma force_active on
struct unk_t {
    char _data[0x48];
    int field;
};

extern "C" void fn_27_25C524(unk_t* self) {
    self->field = 11;
}
