#pragma force_active on
extern "C" {
void fn_70_20FC(void* self, int arg);
void __dl__FPv(void* p);
}

extern "C" void* fn_70_6A00(void* p, int flag) {
    if (p != 0) {
        fn_70_20FC(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
