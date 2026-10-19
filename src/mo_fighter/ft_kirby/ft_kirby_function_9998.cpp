#pragma force_active on
extern "C" {
void* fn_27_14FCF4(void*, short);
}

extern "C" void* fn_96_9998(void* object, short deleting) {
    if (object != 0) {
        fn_27_14FCF4(object, static_cast<short>(-1));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
