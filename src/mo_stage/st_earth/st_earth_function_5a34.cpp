#pragma force_active on
extern "C" {
void __dt__14snd3DGeneratorFv(void*, int);
void fn_66_2C60(void*, int);
void __dl__FPv(void*);

void* fn_66_5A34(void* ptr, int size) {
    if (ptr != 0) {
        __dt__14snd3DGeneratorFv((char*)ptr + 0x198, -1);
        fn_66_2C60(ptr, 0);
        if (size > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}
