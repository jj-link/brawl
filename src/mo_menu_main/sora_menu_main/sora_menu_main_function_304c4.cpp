#pragma force_active on
extern "C" {
extern unsigned char lbl_2_data_3C20[];
void fn_800B8A0C(void*, int);
void fn_2_37C(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_2_304C4(unsigned char* object, int deleting) {
    if (object) {
        *reinterpret_cast<void**>(object + 0x668) = lbl_2_data_3C20;
        *reinterpret_cast<void**>(object + 0x66C) = lbl_2_data_3C20 + 0x28;
        fn_800B8A0C(*reinterpret_cast<void**>(object + 0x678), 1);
        fn_800B8A0C(*reinterpret_cast<void**>(object + 0x67C), 1);
        if (object) {
            __destroy_arr(object + 0x48, fn_2_37C, 0xA8, 9);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
