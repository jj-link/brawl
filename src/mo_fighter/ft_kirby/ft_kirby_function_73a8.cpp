#pragma force_active on
extern "C" void* fn_96_7348(void* object, short deleting);
extern "C" void* fn_96_7284(void* object, short deleting);

extern "C" void* fn_96_73A8(void* object, short deleting) {
    if (object != 0) {
        fn_96_7348(static_cast<unsigned char*>(object) + 0x16D8, -1);
        fn_96_7284(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
