#pragma force_active on
extern "C" void* fn_105_3EA0(void* object, short deleting);
extern "C" void* fn_105_3F78(void* object, short deleting);
extern "C" void* fn_105_1E71C(void* object, short deleting);
extern "C" void* fn_105_3FD8(void* object, short deleting);
extern "C" void* fn_105_4100(void* object, short deleting);
extern "C" void* fn_27_C74E8(void* object, short deleting);

extern "C" void* fn_105_1E680(void* object, short deleting) {
    if (object != 0) {
        fn_105_3EA0(static_cast<unsigned char*>(object) + 0x120, -1);
        fn_105_3F78(static_cast<unsigned char*>(object) + 0x10C, -1);
        fn_105_1E71C(static_cast<unsigned char*>(object) + 0xEC, -1);
        fn_105_3FD8(static_cast<unsigned char*>(object) + 0x48, -1);
        fn_105_4100(static_cast<unsigned char*>(object) + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
