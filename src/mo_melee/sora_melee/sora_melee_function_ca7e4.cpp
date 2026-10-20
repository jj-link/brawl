#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void fn_27_A6978(void*, int);
void __dl__FPv(void*);

void* fn_27_CA7E4(void* p, int flag) {
    if (p) {
        __destroy_arr((char*)p + 0xC, fn_27_A6978, 0x24, 0xD);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
