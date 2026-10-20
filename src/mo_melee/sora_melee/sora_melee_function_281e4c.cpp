#pragma force_active on
extern "C" {
void fn_27_1A1B88(void*, short);
void fn_27_AB18C(void*, short);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_27_281E4C(void* obj, short flag) {
    if (obj) {
        __destroy_arr((char*)obj + 0x38, (void (*)(void*, int))fn_27_1A1B88, 0x2c, 1);
        if ((char*)obj + 0x18)
            __destroy_arr((char*)obj + 0x24, (void (*)(void*, int))fn_27_AB18C, 0x14, 1);
        if (flag > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
