#pragma force_active on
extern "C" void* fn_27_1966BC(void*, short);

extern "C" void* fn_99_2B8C(void* object, short deleting) {
    if (object) {
        fn_27_1966BC(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
