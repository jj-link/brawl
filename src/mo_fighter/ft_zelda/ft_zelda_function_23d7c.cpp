#pragma force_active on
extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_27_21038(void*, short);
extern "C" void* fn_104_480C(void*, short);

extern "C" void* fn_104_23D7C(void* object, short deleting) {
    if (object != 0) {
        short val = -1;
        fn_27_13C90(static_cast<unsigned char*>(object) + 0x9C, val);
        fn_27_21038(static_cast<unsigned char*>(object) + 0x88, val);
        fn_104_480C(object, val);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
