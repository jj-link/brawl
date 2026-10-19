#pragma force_active on
extern "C" {
void* fn_27_19816C(void*, short);

void* fn_91_85C8(void* object, short deleting) {
    if (object != 0) {
        fn_27_19816C(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
