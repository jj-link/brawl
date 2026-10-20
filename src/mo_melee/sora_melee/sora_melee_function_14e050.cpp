#pragma force_active on
extern "C" {
void* fn_27_A78FC(void*, short);
void* fn_27_A3704(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_27_14E050(void* p, short memberDeleting) {
    if (p) {
        fn_27_A78FC((char*)p + 0x4c, -1);
        fn_27_A3704(p, 0);
        if (memberDeleting > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
