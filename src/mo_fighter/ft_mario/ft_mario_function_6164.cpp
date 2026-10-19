#pragma force_active on
extern "C" {
void* fn_91_61D0(void*, short);
void* fn_91_622C(void*, short);

void* fn_91_6164(void* object, short deleting) {
    if (object != 0) {
        fn_91_61D0(static_cast<unsigned char*>(object) + 0x50, static_cast<short>(-1));
        fn_91_622C(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
