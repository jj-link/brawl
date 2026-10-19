#pragma force_active on
extern "C" void* fn_27_C21DC(void*, short);

extern "C" void* fn_99_2BE8(void* object, short deleting) {
    if (object) {
        fn_27_C21DC(object, -1);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
