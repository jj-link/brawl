#pragma force_active on
extern "C" {
void* fn_27_CC7EC(void*, short);
void* fn_91_2958(void* object, short deleting) {
    if (object != 0) {
        fn_27_CC7EC(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
