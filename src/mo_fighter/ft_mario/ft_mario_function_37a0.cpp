#pragma force_active on
extern "C" {
void fn_27_4B53C(void*, short);
void fn_27_19C45C(void*, short);

void* fn_91_37A0(void* object, short deleting) {
    if (object != 0) {
        fn_27_4B53C(static_cast<unsigned char*>(object) + 0x17c, static_cast<short>(-1));
        fn_27_19C45C(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
