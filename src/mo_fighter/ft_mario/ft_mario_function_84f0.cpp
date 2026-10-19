#pragma force_active on
extern "C" {
void* fn_27_B64B8(void*, short);

void* fn_91_84F0(void* object, short deleting) {
    if (object != 0) {
        fn_27_B64B8(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
