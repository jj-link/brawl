#pragma force_active on
extern "C" void fn_27_D3B18(void* p, short x);
extern "C" void fn_27_D3B38(void* p, short x, signed char y);
extern "C" char lbl_112_data_75CC[];

extern "C" void* fn_112_EEE4(void** self, short a, signed char b) {
    fn_27_D3B18(self, 6);
    *self = lbl_112_data_75CC;
    fn_27_D3B38(self, a, b);
    return self;
}
