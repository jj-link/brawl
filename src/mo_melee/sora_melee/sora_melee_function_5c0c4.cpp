#pragma force_active on
extern "C" void fn_27_5C6D8(void);

struct Fn27_5C0C4 {
    char pad[0x28];
    int unk28;
    char pad2[8];
    int unk34;
};

extern "C" void fn_27_5C0C4(Fn27_5C0C4* self) {
    fn_27_5C6D8();
    self->unk28 = 0;
    self->unk34 = 1;
}
