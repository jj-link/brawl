#pragma force_active on
extern "C" {
void fn_2_37C(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_2_25F04(char* self, int del) {
    if (self) {
        if (self) {
            __destroy_arr(self + 0x48, fn_2_37C, 0xA8, 9);
        }
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
