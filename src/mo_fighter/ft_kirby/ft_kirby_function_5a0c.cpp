#pragma force_active on
extern "C" void* fn_96_4CE8(void* object, short deleting);
extern "C" void* fn_96_4C88(void* object, short deleting);
extern "C" void* fn_96_59B0(void* object, short deleting);
extern "C" void* fn_96_5938(void* object, short deleting);
extern "C" void* fn_96_4F38(void* object, short deleting);
extern "C" void* fn_27_C74E8(void* object, short deleting);
extern "C" void operator delete(void*);

extern "C" void* fn_96_5A0C(void* object, short deleting) {
    if (object != 0) {
        fn_96_4CE8(static_cast<unsigned char*>(object) + 0x10E0, -1);
        fn_96_4C88(static_cast<unsigned char*>(object) + 0x10CC, -1);
        fn_96_59B0(static_cast<unsigned char*>(object) + 0x9C0, -1);
        fn_96_5938(static_cast<unsigned char*>(object) + 0x14C, -1);
        fn_96_4F38(static_cast<unsigned char*>(object) + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
