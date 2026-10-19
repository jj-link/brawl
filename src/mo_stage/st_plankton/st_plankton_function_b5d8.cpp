#pragma force_active on
extern "C" {

void __dl__FPv(void*);
void __dt__14snd3DGeneratorFv(void*, int);
void fn_74_26B0(void*, int);

void* fn_74_B5D8(void* this_ptr, int flag) {
    if (this_ptr) {
        __dt__14snd3DGeneratorFv((char*)this_ptr + 0x174, -1);
        fn_74_26B0(this_ptr, 0);
        if (flag > 0) {
            __dl__FPv(this_ptr);
        }
    }
    return this_ptr;
}

}
