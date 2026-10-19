#pragma force_active on
void operator delete(void*);
extern "C" void* fn_125_100D0(void*, short);
extern "C" void* fn_125_101EC(void*, short);

extern "C" void* fn_125_10060(void* object, short deleting) {
    if (object != 0) {
        fn_125_100D0(static_cast<unsigned char*>(object) + 0x1730, -1);
        fn_125_101EC(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
