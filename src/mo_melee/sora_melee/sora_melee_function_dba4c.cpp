#pragma force_active on
extern "C" {
void* fn_27_84518(void* p, int n);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_27_DBA4C(void* p, int n) {
    if (p) {
        __destroy_arr((char*)p + 0xC, (void (*)(void*, int))fn_27_84518, 0xC, 4);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
