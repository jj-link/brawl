#pragma force_active on
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void fn_2_37C(void*, int);

extern "C" {
void* fn_2_1D410(void* p, int deleting) {
    if (p) {
        if (p) {
            __destroy_arr((char*)p + 0x48, fn_2_37C, 0xA8, 9);
        }
        if (deleting > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
