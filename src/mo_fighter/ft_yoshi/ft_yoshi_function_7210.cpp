#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_565F0(void*, short);
extern "C" void* fn_95_727C(void* p, short n);

extern "C" void* fn_95_7210(void* p, short n) {
    if (p != 0) {
        fn_27_565F0(static_cast<unsigned char*>(p) + 0x14, -1);
        fn_95_727C(p, -1);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
