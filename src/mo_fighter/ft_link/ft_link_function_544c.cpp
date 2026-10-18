#pragma force_active on
extern "C" void* fn_93_4728(void*, short);
extern "C" void* fn_93_46C8(void*, short);
extern "C" void* fn_93_53F0(void*, short);
extern "C" void* fn_93_5378(void*, short);
extern "C" void* fn_93_4978(void*, short);
extern "C" void* fn_27_C74E8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_93_544C(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_93_4728(static_cast<unsigned char*>(object) + 0xdc0, memberDeleting);
        fn_93_46C8(static_cast<unsigned char*>(object) + 0xdac, memberDeleting);
        fn_93_53F0(static_cast<unsigned char*>(object) + 0x930, memberDeleting);
        fn_93_5378(static_cast<unsigned char*>(object) + 0xbc, memberDeleting);
        fn_93_4978(static_cast<unsigned char*>(object) + 0x10, memberDeleting);
        fn_27_C74E8(object, memberDeleting);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
