#pragma force_active on
extern "C" {
void* fn_801C4B68(void* self, int deleting);
void __dl__FPv(void* p);
}

extern "C" void* fn_801C2074(void* arg0, int arg1) {
    if (arg0 != 0) {
        fn_801C4B68(arg0, 0);
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
