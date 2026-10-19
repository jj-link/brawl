#pragma force_active on
extern "C" {
void fn_2_37C(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_2_14DE0(unsigned char* object, int deleting) {
    if (object) {
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
