#pragma force_active on
extern "C" void* fn_125_10060(void*, short);
extern "C" void* fn_27_1D81C8(void*, short);

extern "C" void* fn_125_FFF0(void* object, short deleting) {
    if (object != 0) {
        fn_125_10060(static_cast<unsigned char*>(object) + 0xcc, -1);
        fn_27_1D81C8(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
