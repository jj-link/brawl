#pragma force_active on
extern "C" void fn_27_19BFCC(void*, short);

extern "C" void* fn_123_5EF8(void* p, short flag) {
    if (p != 0) {
        fn_27_19BFCC(p, -1);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
