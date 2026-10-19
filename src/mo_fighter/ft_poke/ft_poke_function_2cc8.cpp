#pragma force_active on
extern "C" {

void* fn_27_BED74(void* object, short kind);
void __dl__FPv(void* ptr);

void* fn_116_2CC8(void* ptr, short kind) {
    void* result = ptr;
    if (ptr != 0) {
        fn_27_BED74(ptr, static_cast<short>(-1));
        if (kind > 0) {
            __dl__FPv(ptr);
        }
    }
    return result;
}

} // extern "C"
