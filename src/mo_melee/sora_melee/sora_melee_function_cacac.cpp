#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void fn_27_A6978(void*, int);
}

extern "C" void* fn_27_CACAC(unsigned char* obj, int flag) {
    if (obj) {
        __destroy_arr(obj + 0xc, fn_27_A6978, 0x24, 7);
        if (flag > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
