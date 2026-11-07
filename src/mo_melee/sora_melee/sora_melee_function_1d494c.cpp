#pragma force_active on
extern "C" {
void* fn_27_1D5500(void*, int);
void* fn_27_1D7210(void*, int);
void* fn_27_1D618C(void*, int);
void* fn_27_1D6104(void*, int);
void* fn_27_1D6148(void*, int);
void* fn_27_1D60C0(void*, int);
void* fn_27_1D607C(void*, int);
void* fn_27_1D4B40(void*, int);
void __dl__FPv(void*);

void* fn_27_1D494C(char* self, int flag) {
    if (self) {
        fn_27_1D5500(self + 0x490, -1);
        fn_27_1D7210(self + 0x40c, -1);
        fn_27_1D618C(self + 0x400, -1);
        fn_27_1D6104(self + 0x3ff, -1);
        fn_27_1D6148(self + 0x3fe, -1);
        fn_27_1D60C0(self + 0x3fd, -1);
        fn_27_1D607C(self + 0x3fc, -1);
        fn_27_1D4B40(self + 0x1b0, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
