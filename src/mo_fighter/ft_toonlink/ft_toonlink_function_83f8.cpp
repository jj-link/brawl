#pragma force_active on
extern "C" void* fn_27_BED74(void*, short);
void operator delete(void*);

extern "C" void* fn_121_83F8(void* p, short flag) {
    if (p != 0) {
        fn_27_BED74(p, static_cast<short>(-1));
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
