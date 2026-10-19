#pragma force_active on
extern "C" void fn_27_19BFCC(void*, short);

extern "C" void* fn_99_5194(void* object, short deleting) {
    if (object) {
        fn_27_19BFCC(object, -1);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
