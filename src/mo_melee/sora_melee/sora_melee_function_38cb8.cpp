#pragma force_active on
typedef unsigned char u8;

extern "C" {
void __dt__8clTargetFv(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_27_38CB8(u8* object, int deleting) {
    if (object) {
        __destroy_arr(object + 0xc, __dt__8clTargetFv, 0x8, 0x7);
        if (deleting > 0)
            __dl__FPv(object);
    }
    return object;
}
}
