#pragma force_active on
extern "C" {
void __dt__14snd3DGeneratorFv(void* self, int flags);
void __dl__FPv(void* arr);

void* fn_27_57D6C(void* a, int b) {
    if (a) {
        __dt__14snd3DGeneratorFv((char*)a + 0xc, -1);
        if (b > 0)
            __dl__FPv(a);
    }
    return a;
}
}
