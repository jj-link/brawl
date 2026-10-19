#pragma force_active on
extern "C" {
void fn_27_2464C8(void* self, int arg);
extern unsigned char lbl_27_data_4E9F0[0x6C];
}

struct Obj {
    char pad[0x3C];
    unsigned char* m_data;
};

extern "C" Obj* fn_27_246ACC(Obj* self) {
    fn_27_2464C8(self, 1);
    self->m_data = lbl_27_data_4E9F0;
    return self;
}
