#pragma force_active on
extern "C" void* fn_27_CC7EC(void*, short);

extern "C" void* fn_99_5E2C(void* object, short deleting) {
    if (object) {
        fn_27_CC7EC(object, -1);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
