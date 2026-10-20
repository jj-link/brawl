#pragma force_active on
typedef unsigned char u8;

extern "C" {
void fn_27_2E3D38(void* self, int arg);
void fn_27_36513C(void* self, int arg);
void* fn_27_1D81C8(void* self, short flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_27_3650C0(void* self, int doDelete) {
    if (self) {
        if ((unsigned long)self + 0xCC) {
            fn_27_2E3D38((u8*)self + 0x1700, -1);
            fn_27_36513C((u8*)self + 0xCC, 0);
        }
        fn_27_1D81C8(self, 0);
        if (doDelete > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
