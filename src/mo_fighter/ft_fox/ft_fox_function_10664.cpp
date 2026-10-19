#pragma force_active on
extern "C" {
void* fn_97_106C0(void* ptr, short count);
void* fn_97_10664(void* ptr, short flag);
void __dl__FPv(void* ptr);
}

extern "C" void* fn_97_10664(void* ptr, short flag) {
    if (ptr != 0) {
        fn_97_106C0(ptr, 0);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
