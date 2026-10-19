#pragma force_active on
extern "C" void* fn_117_1F50(void*, short);
extern "C" void* fn_117_1FAC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_117_5470(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = 0;
        fn_117_1F50(members + 0x14, memberDeleting);
        fn_117_1FAC(members + 8, memberDeleting);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
