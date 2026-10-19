#pragma force_active on
extern "C" {
extern char lbl_122_data_EDCC[];
void fn_27_D3B18(void* p, short x);
void fn_27_D3B38(void* self, short a, signed char b);
}

extern "C" void* fn_122_243A0(void* self, short a, signed char b) {
    short s = 6;
    fn_27_D3B18(self, s);
    *(void**)self = lbl_122_data_EDCC;
    fn_27_D3B38(self, a, b);
    return self;
}
