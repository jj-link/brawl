#pragma force_active on
extern "C" {
void fn_27_84398(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_27_1B24D8(void* p, int flag) {
    if (p) {
        __destroy_arr((char*)p + 0xC, fn_27_84398, 0xC, 0x11);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
