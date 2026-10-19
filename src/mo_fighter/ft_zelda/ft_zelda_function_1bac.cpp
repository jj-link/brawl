#pragma force_active on
extern "C" {
void fn_104_1B48(void* obj, short flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_104_1BAC(void* obj, short flag) {
    if (obj != 0) {
        fn_104_1B48(obj, 0);
        if (flag > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
