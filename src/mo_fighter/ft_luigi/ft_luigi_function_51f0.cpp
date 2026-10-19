#pragma force_active on
extern "C" void* fn_27_5B39C(void*, short);

extern "C" void* fn_99_51F0(void* object, short deleting) {
    if (object) {
        fn_27_5B39C(object, -1);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
