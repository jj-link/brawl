#pragma force_active on
extern "C" {

void fn_27_5B39C(void*, short);
void __dl__FPv(void*);

void* fn_122_593C(void* ptr, short flag) {
    if (ptr != 0) {
        fn_27_5B39C(ptr, static_cast<short>(-1));
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}

} // extern "C"
