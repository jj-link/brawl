#pragma force_active on
extern "C" {
void* fn_27_1A3328(void*, short);

void* fn_91_522C(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A3328(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
