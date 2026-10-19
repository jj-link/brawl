#pragma force_active on
extern "C" {
void fn_27_272668(void*);
extern char lbl_40_data_81A0[];
extern const float lbl_40_rodata_408;
}

extern "C" char* fn_40_27800(char* self) {
    fn_27_272668(self);
    *(char**)(self + 0x3c) = lbl_40_data_81A0;
    *(int*)(self + 0x154) = 0;
    *(int*)(self + 0x158) = 0;
    *(int*)(self + 0x15c) = 0;
    *(int*)(self + 0x160) = 0;
    *(int*)(self + 0x164) = 0;
    *(int*)(self + 0xe4) = 0x1f;
    *(float*)(self + 0xf8) = lbl_40_rodata_408;
    return self;
}
