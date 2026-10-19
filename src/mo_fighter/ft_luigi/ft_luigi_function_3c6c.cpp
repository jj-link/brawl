#pragma force_active on
extern "C" void* fn_99_3CC8(void* object, short deleting);

extern "C" void* fn_99_3C6C(void* object, short deleting) {
    if (object) {
        fn_99_3CC8(object, 0);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
