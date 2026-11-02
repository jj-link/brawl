#pragma force_active on
typedef unsigned char u8;

extern "C" {
void* fn_27_93100(void*, short);
void fn_27_CDA70(void*, int);
void fn_27_3335CC(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_27_3331F4(u8* self, int flag) {
    if (self) {
        fn_27_93100(self + 0xBC20, -1);
        if (self + 0x2C && self + 0x2C && self + 0x34 && self + 0x34 && self + 0x38) {
            fn_27_3335CC(self + 0x9CD0, -1);
            if (self + 0x3C) {
                fn_27_3335CC(self + 0x7D84, -1);
                if (self + 0x40) {
                    fn_27_3335CC(self + 0x5E38, -1);
                    if (self + 0x44) {
                        fn_27_3335CC(self + 0x3EEC, -1);
                        if (self + 0x48) {
                            fn_27_3335CC(self + 0x1FA0, -1);
                            if (self + 0x4C) {
                                fn_27_3335CC(self + 0x54, -1);
                            }
                        }
                    }
                }
            }
        }
        if (self + 0x10) {
            __destroy_arr(self + 0x1C, fn_27_CDA70, 0x10, 1);
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
