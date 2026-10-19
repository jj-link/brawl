#pragma force_active on
extern "C" void* fn_27_14FCF4(void*, short);

extern "C" void* fn_99_2F40(void* object, short deleting) {
    if (object) {
        fn_27_14FCF4(object, -1);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
