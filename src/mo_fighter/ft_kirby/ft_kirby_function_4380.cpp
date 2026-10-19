#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_565F0(void*, short);
extern "C" void* fn_96_4340(void*, short);

extern "C" void* fn_96_4380(void* p, short flag) {
    if (p != 0) {
        fn_27_565F0(static_cast<unsigned char*>(p) + 0x14, -1);
        fn_96_4340(p, -1);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
