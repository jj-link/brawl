#pragma force_active on
typedef signed short s16;
typedef signed char s8;

extern "C" {
    void fn_27_D4DBC(void* obj, s16 v);
    void fn_27_D4DDC(void* self, s16 a, s8 b);
    extern char lbl_122_data_DFC4[];
}

extern "C" void* fn_122_24418(void* self, s16 a, s8 b) {
    fn_27_D4DBC(self, 0x11);
    *(char**)self = lbl_122_data_DFC4;
    fn_27_D4DDC(self, a, b);
    return self;
}
