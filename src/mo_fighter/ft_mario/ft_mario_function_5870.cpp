#pragma force_active on
extern "C" {
void* fn_91_AC50(void*, short);
void* fn_91_57C0(void*, short);
void* fn_91_56F4(void*, short);

void* fn_91_5870(void* object, short deleting) {
    if (object != 0) {
        fn_91_AC50(static_cast<unsigned char*>(object) + 0xe0, static_cast<short>(-1));
        fn_91_57C0(static_cast<unsigned char*>(object) + 0x30, static_cast<short>(-1));
        fn_91_56F4(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
