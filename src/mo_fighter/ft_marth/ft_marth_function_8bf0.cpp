#pragma force_active on
extern "C" {
void fn_106_8B90(void*, short);
void __dl__FPv(void*);

void* fn_106_8BF0(void* p, int flag) {
    if (p != 0) {
        fn_106_8B90((char*)p + 8, -1);
        if ((short)flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
