#pragma force_active on
extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_27_14033C(void*, void*);
void* fn_27_B5048(void*, void*, void*, void*, void*, const void*);
extern const char lbl_27_data_2AB90[], lbl_27_bss_A48[];
extern const char lbl_93_data_337C[], lbl_93_data_3BF8[];
}

extern "C" void* fn_93_2080(char* self, int unused, char* accesser) {
    void* res = *reinterpret_cast<void**>(static_cast<char*>(__dynamic_cast(
        *reinterpret_cast<void**>(accesser + 8), 0x3C,
        lbl_93_data_337C, lbl_93_data_3BF8, 1)) + 0x10C);
    fn_27_14033C(self + 4, res);

    void* res2 = *reinterpret_cast<void**>(static_cast<char*>(__dynamic_cast(
        *reinterpret_cast<void**>(accesser + 8), 0x3C,
        lbl_93_data_337C, lbl_93_data_3BF8, 1)) + 0x10C);
    char* handle = self + 0x18;
    fn_27_14033C(handle, res2);

    *reinterpret_cast<const void**>(handle) = lbl_27_data_2AB90;
    *reinterpret_cast<int*>(handle + 0x14) = -1;
    fn_27_B5048(self + 0x30, self + 4, self + 4, handle, accesser, lbl_27_bss_A48);
    return self;
}
