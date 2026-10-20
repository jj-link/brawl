#pragma force_active on
extern "C" {
void fn_27_300DC8(void*, int);
void fn_27_300E8C(void*, int);
void* fn_27_1D81C8(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_27_303EBC(void* self, int flag) {
    if (self) {
        if (self) {
            if ((int)(char*)self + 0xCC) {
                fn_27_300DC8((char*)self + 0x182C, -1);
                fn_27_300E8C((char*)self + 0xCC, 0);
            }
            fn_27_1D81C8(self, 0);
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}