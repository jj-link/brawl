#pragma force_active on
extern "C" {
void* fn_113_67C4(void* ptr, short count);
void __dl__FPv(void* p);
}

extern "C" void* fn_113_6804(void* ptr, short flag) {
    if (ptr != 0) {
        fn_113_67C4(ptr, 0);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
