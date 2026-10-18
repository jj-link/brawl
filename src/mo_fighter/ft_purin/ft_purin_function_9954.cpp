#pragma force_active on
extern "C" {
void fn_124_98F4(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_124_9954(void* p, int flag) {
    if (p != 0) {
        fn_124_98F4((char*)p + 8, -1);
        if ((short)flag > 0)
            __dl__FPv(p);
    }
    return p;
}
