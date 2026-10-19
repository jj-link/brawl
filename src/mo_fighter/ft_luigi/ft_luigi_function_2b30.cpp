#pragma force_active on
extern "C" void* fn_27_5BFA0(void*, short);

extern "C" void* fn_99_2B30(void* object, short deleting) {
    if (object) {
        fn_27_5BFA0(object, -1);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
