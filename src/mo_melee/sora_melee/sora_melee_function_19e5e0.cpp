#pragma force_active on
struct fn_27_19E5E0_Obj;

extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void fn_27_46700(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" {
void* fn_27_19E5E0(fn_27_19E5E0_Obj* obj, int flag) {
    if (obj) {
        __destroy_arr((char*)obj + 0xc, fn_27_46700, 0x60, 0x14);
        if (flag > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
}
