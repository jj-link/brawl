#pragma force_active on
extern "C" void fn_27_1E847C(void* self, int size, void* p);
extern "C" char lbl_27_data_8C240[];
extern "C" char lbl_27_bss_54EC[];

extern "C" {
void* fn_27_3413A8(void* self, int del) {
    if (self) {
        *(char**)self = lbl_27_data_8C240 + 8;
        *(char**)((char*)self + 8) = lbl_27_data_8C240;
        fn_27_1E847C(self, 0x44, lbl_27_bss_54EC);
        if (del > 0) {
            operator delete(self);
        }
    }
    return self;
}
}
