#pragma force_active on
extern "C" void* fn_41_35C44(void* self, short flags);
extern "C" void* fn_41_35A8C(void* p1, short p2);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_35CB0(void* p1, short p2) {
    if (p1 != 0) {
        fn_41_35C44((char*)p1 + 0x68, -1);
        fn_41_35A8C(p1, 0);
        if (p2 > 0) {
            __dl__FPv(p1);
        }
    }
    return p1;
}
