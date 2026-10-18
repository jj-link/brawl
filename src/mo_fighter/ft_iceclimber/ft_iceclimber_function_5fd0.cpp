#pragma force_active on
extern "C" void* fn_105_6030(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_105_5FD0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_105_6030(members + 8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
