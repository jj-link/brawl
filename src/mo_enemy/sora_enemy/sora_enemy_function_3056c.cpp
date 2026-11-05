#pragma force_active on
extern "C" void* fn_27_A0C74(void*, short);
extern "C" void* fn_41_27D8(void*, short);
extern "C" void* fn_27_D320C(void*, short);
extern "C" void* fn_27_D3464(void*, short);
extern "C" void* fn_41_21E4(void*, short);
extern "C" void* fn_41_2D8F4(void*, short);
extern "C" void* fn_41_301E4(void*, short);
void operator delete(void*);

extern "C" void* fn_41_3056C(void* p, short flag) {
    if (p != 0) {
        short n = -1;
        fn_27_A0C74((char*)p + 0x22bc, n);
        fn_41_27D8((char*)p + 0x226c, n);
        fn_27_D320C((char*)p + 0x224c, n);
        fn_27_D3464((char*)p + 0x2238, n);
        n = 0;
        fn_41_21E4((char*)p + 0x2178, n);
        fn_41_2D8F4((char*)p + 0x216c, n);
        fn_41_301E4((char*)p + 0xc, n);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
