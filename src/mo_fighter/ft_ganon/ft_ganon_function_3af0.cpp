#pragma force_active on
extern "C" void* fn_109_3B50(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_109_3AF0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* member = static_cast<unsigned char*>(object) + 0x38;
        fn_109_3B50(member, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
