#pragma force_active on
extern "C" void fn_41_679B8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_67A24(void* ptr, short flag) {
    if (ptr != 0) {
        fn_41_679B8((char*)ptr + 4, -1);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
