#pragma force_active on
extern "C" void fn_27_19BFCC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_93_3FB8(void* object, short deleting) {
    if (object != 0) {
        fn_27_19BFCC(object, static_cast<short>(-1));
        if ((signed)deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
