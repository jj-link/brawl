#pragma force_active on
extern "C" {
void fn_27_19BFCC(void*, short);
void __dl__FPv(void*);

void* fn_109_5964(void* object, short deleting) {
    if (object != 0) {
        fn_27_19BFCC(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
