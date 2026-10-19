#pragma force_active on
extern "C" {
void fn_27_3544C(void*, short);

void* fn_91_203C(void* object, short deleting) {
    if (object != 0) {
        fn_27_3544C(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
