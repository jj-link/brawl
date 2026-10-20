#pragma force_active on
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void* fn_107_7294(void*, short);

extern "C" void* fn_107_721C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* p = static_cast<unsigned char*>(object);
        fn_27_1A15B8(p + 0x138, -1);
        if (object != 0) {
            fn_107_7294(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
