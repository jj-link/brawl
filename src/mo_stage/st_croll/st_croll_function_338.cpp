#pragma force_active on
extern "C" {
void fn_8007291C(void* p);
void fn_800726A8(void* p, int flag);
void __dl__FPv(void* p);
void* fn_90_338(char* self, int flag);
}

void* fn_90_338(char* self, int flag) {
    if (self != 0) {
        if (*(int*)(self + 0x34) != 0) {
            fn_8007291C(self + 0x10);
        }
        if (self + 0x10 != 0) {
            fn_800726A8(self + 0x10, 0);
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
