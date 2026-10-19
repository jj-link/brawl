#pragma force_active on
extern "C" {
void* fn_27_A0C74(void*, short);
void* fn_91_61D0(void* object, short deleting) {
    if (object != 0) {
        fn_27_A0C74(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
