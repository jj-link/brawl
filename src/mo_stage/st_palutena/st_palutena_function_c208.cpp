#pragma force_active on
extern "C" {
void fn_67_20BC(void* self, int flag);
void* fn_67_C208(void* p, int flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_67_C208(void* p, int flag) {
    if (p != 0) {
        fn_67_20BC(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
