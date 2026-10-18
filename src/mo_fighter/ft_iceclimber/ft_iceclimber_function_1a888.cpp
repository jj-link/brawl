#pragma force_active on
extern "C" void* fn_105_3EA0(void* object, short deleting);
extern "C" void* fn_105_3F78(void* object, short deleting);
extern "C" void* fn_105_1A924(void* object, short deleting);
extern "C" void* fn_105_3FD8(void* object, short deleting);
extern "C" void* fn_105_4100(void* object, short deleting);
extern "C" void* fn_27_C74E8(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_105_1A888(void* object, short deleting) {
    if (object != 0) {
        unsigned char* p = static_cast<unsigned char*>(object);
        fn_105_3EA0(p + 0x11C, -1);
        fn_105_3F78(p + 0x108, -1);
        fn_105_1A924(p + 0xEC, -1);
        fn_105_3FD8(p + 0x48, -1);
        fn_105_4100(p + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
