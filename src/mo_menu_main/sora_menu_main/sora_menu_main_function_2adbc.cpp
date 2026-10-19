#pragma force_active on
extern "C" {
void fn_2_37C(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_2_2ADBC(char* obj, int flag) {
    if (obj) {
        if (obj && obj && obj) {
            __destroy_arr(obj + 0x48, fn_2_37C, 0xA8, 9);
        }
        if (flag > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
