#pragma force_active on
extern "C" {
void fn_27_19C818(void*, short);
void* fn_91_2E8C(void* object, short deleting) {
    if (object != 0) {
        fn_27_19C818(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
