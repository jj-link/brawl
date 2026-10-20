#pragma force_active on
extern "C" void* fn_27_93100(void*, short);
extern "C" void* fn_27_19EB34(void*, short);
extern "C" void* fn_27_1A4E94(void*, short);
extern "C" void* fn_121_17378(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_121_172F4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_27_93100(members + 0x1710, memberDeleting);
        fn_121_17378(members + 0x2c, memberDeleting);
        fn_27_19EB34(members + 0x10, memberDeleting);
        fn_27_1A4E94(object, memberDeleting);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
