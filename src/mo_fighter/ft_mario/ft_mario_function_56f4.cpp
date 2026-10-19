#pragma force_active on
extern "C" {
void* fn_91_1A14(void*, short);
void* fn_91_5760(void*, short);

void* fn_91_56F4(void* object, short deleting) {
    if (object != 0) {
        fn_91_1A14(static_cast<unsigned char*>(object) + 0x20, static_cast<short>(0));
        fn_91_5760(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
