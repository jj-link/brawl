#pragma force_active on
extern "C" {
void fn_27_1999C4(void*, int, int);
void fn_27_19BF3C(void*, int, int);
void fn_27_150320(void*, void*, short, void*, void*);
}

extern "C" void* fn_106_6104(char* self, void* arg, short arg2) {
    fn_27_1999C4(self, 10, 0);
    fn_27_19BF3C(self + 0x584, 2, 0);
    fn_27_150320(self + 0x5b8, arg, arg2, self, self + 0x584);
    return self;
}
