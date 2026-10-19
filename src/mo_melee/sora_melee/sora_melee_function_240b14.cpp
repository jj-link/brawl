#pragma force_active on
struct Fn27Obj {
    char pad0[0x3C];
    void* m_3c;
    char pad1[0x24];
    unsigned int m_64;
    unsigned int m_68;
};

extern "C" void fn_27_2407E0(Fn27Obj* self);
extern "C" char lbl_27_data_4D970[];

extern "C" Fn27Obj* fn_27_240B14(Fn27Obj* self) {
    fn_27_2407E0(self);
    self->m_64 = 0;
    self->m_3c = lbl_27_data_4D970;
    self->m_68 = 0;
    return self;
}
