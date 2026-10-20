#pragma force_active on
void operator delete(void*);
extern "C" void* fn_96_84FC(void*, short);
extern "C" void* fn_96_5F44(void*, short);
extern "C" void* fn_96_853C(void*, short);

extern "C" void* fn_96_2CAF8(void* object, short deleting) {
    if (object != 0) {
        fn_96_84FC(static_cast<unsigned char*>(object) + 0xE0, -1);
        fn_96_5F44(static_cast<unsigned char*>(object) + 0x30, -1);
        fn_96_853C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
