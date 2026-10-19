#pragma force_active on
extern "C" void fn_27_5B39C(void*, short);
void operator delete(void*);

extern "C" void* fn_94_5DCC(void* p, short flags) {
    if (p != 0) {
        fn_27_5B39C(p, static_cast<short>(-1));
        if (flags > 0) {
            operator delete(p);
        }
    }
    return p;
}
