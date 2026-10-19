#pragma force_active on
extern "C" {
void fn_48_3A6C(void* p, int n);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void* fn_48_3AAC(void* arg, int n);
}

void* fn_48_3AAC(void* arg, int n) {
    void* obj = arg;
    if (obj) {
        __destroy_arr((char*)obj + 0xC, fn_48_3A6C, 8, 6);
        if (n > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
