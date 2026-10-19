#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void fn_2_37C(void*, int);
}

extern "C" void* fn_2_140A8(void* obj, int deleting) {
    if (obj != 0) {
        if (obj != 0) {
            __destroy_arr((char*)obj + 0x48, fn_2_37C, 0xA8, 9);
        }
        if (deleting > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
