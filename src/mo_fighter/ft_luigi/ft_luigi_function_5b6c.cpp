#pragma force_active on
extern "C" void fn_27_19C818(void*, short);

extern "C" void* fn_99_5B6C(void* object, short deleting) {
    if (object) {
        fn_27_19C818(object, -1);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
