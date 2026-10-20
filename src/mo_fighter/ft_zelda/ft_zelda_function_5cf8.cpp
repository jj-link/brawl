#pragma force_active on
extern "C" void* fn_104_40F4(void*, short);
extern "C" void* fn_104_5D70(void*, short);
extern "C" void* fn_27_19E99C(void*, short);

extern "C" void* fn_104_5CF8(void* object, short deleting) {
    if (object != 0) {
        fn_104_40F4(static_cast<unsigned char*>(object) + 0x85c, -1);
        fn_104_5D70(static_cast<unsigned char*>(object) + 0x19c, -1);
        fn_27_19E99C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
