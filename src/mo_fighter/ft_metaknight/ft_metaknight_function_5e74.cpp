#pragma force_active on
extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_27_14033C(void*, void*);
void* fn_27_B5048(void*, void*, void*, void*, void*, const void*);
extern const char lbl_111_data_14C8[], lbl_111_data_1D44[];
extern const char lbl_27_data_2AB90[], lbl_27_bss_A48[];
}

extern "C" void* fn_111_5E74(char* self, int, char* other) {
    short one = 1;
    void* res = *reinterpret_cast<void**>(
        static_cast<char*>(__dynamic_cast(*reinterpret_cast<void**>(other + 8), 0x3C,
                                          lbl_111_data_14C8, lbl_111_data_1D44, one)) + 0x10C);
    fn_27_14033C(self + 4, res);

    void* res2 = *reinterpret_cast<void**>(
        static_cast<char*>(__dynamic_cast(*reinterpret_cast<void**>(other + 8), 0x3C,
                                          lbl_111_data_14C8, lbl_111_data_1D44, one)) + 0x10C);
    char* handle = self + 0x18;
    fn_27_14033C(handle, res2);

    *reinterpret_cast<const char**>(handle) = lbl_27_data_2AB90;
    *reinterpret_cast<int*>(handle + 0x14) = -1;

    fn_27_B5048(self + 0x30, self + 4, self + 4, handle, other, lbl_27_bss_A48);
    return self;
}
