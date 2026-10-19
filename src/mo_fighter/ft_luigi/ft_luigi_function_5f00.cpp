#pragma force_active on
extern "C" void* fn_27_14B698(void*, short);

extern "C" void* fn_99_5F00(void* object, short deleting) {
    if (object) {
        fn_27_14B698(object, -1);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
