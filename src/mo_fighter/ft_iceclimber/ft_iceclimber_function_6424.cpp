#pragma force_active on
extern "C" void* fn_105_3EA0(void* object, short deleting);
extern "C" void* fn_105_3F78(void* object, short deleting);
extern "C" void* fn_105_64C0(void* object, short deleting);
extern "C" void* fn_105_651C(void* object, short deleting);
extern "C" void* fn_105_6F34(void* object, short deleting);
extern "C" void* fn_27_C74E8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_105_6424(void* object, short deleting) {
    if (object != 0) {
        fn_105_3EA0(static_cast<unsigned char*>(object) + 0xDD4, -1);
        fn_105_3F78(static_cast<unsigned char*>(object) + 0xDC0, -1);
        fn_105_64C0(static_cast<unsigned char*>(object) + 0x930, -1);
        fn_105_651C(static_cast<unsigned char*>(object) + 0xBC, -1);
        fn_105_6F34(static_cast<unsigned char*>(object) + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
