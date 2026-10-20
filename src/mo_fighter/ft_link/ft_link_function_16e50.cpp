#pragma force_active on
extern "C" void* fn_93_13654(void*, short);
extern "C" void* fn_93_16EE0(void*, short);
extern "C" void* fn_93_16F6C(void*, short);
extern "C" void* fn_93_16FF8(void*, short);
extern "C" void* fn_93_17084(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_93_16E50(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_93_13654(members + 0x4B0, memberDeleting);
        fn_93_16EE0(members + 0x384, memberDeleting);
        fn_93_16F6C(members + 0x258, memberDeleting);
        fn_93_16FF8(members + 0x12C, memberDeleting);
        fn_93_17084(object, memberDeleting);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
