#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void* fn_113_3208(void*, short);

extern "C" void* fn_113_15440(void* object, short deleting) {
    void* result;
    if (object != 0) {
        short baseDeleting = 0;
        fn_113_3208(object, baseDeleting);
        result = object;
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    else {
        result = object;
    }
    return result;
}
