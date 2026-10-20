#pragma force_active on
extern "C" {
void fn_800B8A0C(void*, int);
void fn_2_37C(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
extern unsigned char lbl_2_data_38D8[];

void* fn_2_2CE38(void* object, int shouldDelete) {
    if (object) {
        *(void**)((char*)object + 0x668) = lbl_2_data_38D8;
        fn_800B8A0C(*(void**)((char*)object + 0x66C), 1);
        if (object)
            __destroy_arr((char*)object + 0x48, fn_2_37C, 0xA8, 9);
        if (shouldDelete > 0)
            __dl__FPv(object);
    }
    return object;
}
}
