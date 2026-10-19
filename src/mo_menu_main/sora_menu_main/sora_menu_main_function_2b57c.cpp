#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void* fn_2_2B57C(void* self, int deleting);
void fn_2_37C(void*, int);
}

void* fn_2_2B57C(void* self, int deleting) {
    if (self) {
        if (self) {
            __destroy_arr((char*)self + 0x48, fn_2_37C, 0xA8, 9);
        }
        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
