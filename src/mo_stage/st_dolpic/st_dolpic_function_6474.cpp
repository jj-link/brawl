#pragma force_active on
extern "C" {
extern char lbl_46_data_1D08[];
void fn_46_4570(void* self, int flag);
void __dl__FPv(void* p);
}

extern "C" char* fn_46_6474(char* self, int flag) {
    if (self != 0) {
        *(char**)(self + 0x3c) = lbl_46_data_1D08;
        char* p = *(char**)(self + 0x44);
        char* q = *(char**)p;
        if (q != 0) {
            *(int*)(q + 0xd4) = 0;
        }
        fn_46_4570(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
