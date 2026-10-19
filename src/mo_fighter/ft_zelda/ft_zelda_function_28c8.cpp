#pragma force_active on
extern "C" {

void fn_27_1A5CCC(void* ptr, short flag);
void __dl__FPv(void* ptr);

void* fn_104_28C8(void* ptr, int count) {
    if (ptr != 0) {
        short flag = -1;
        fn_27_1A5CCC(ptr, flag);
        if ((short)count > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}

} // extern "C"
