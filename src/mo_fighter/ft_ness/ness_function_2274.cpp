#pragma force_active on
extern "C" void* fn_101_234C(void* object, short deleting);
extern "C" void* fn_101_2510(void* object, short deleting);
extern "C" void* fn_101_25D8(void* object, short deleting);
extern "C" void* fn_101_2664(void* object, short deleting);
extern "C" void* fn_101_26F0(void* object, short deleting);
extern "C" void* fn_101_277C(void* object, short deleting);
extern "C" void* fn_101_2808(void* object, short deleting);
extern "C" void* fn_101_2894(void* object, short deleting);
extern "C" void* fn_101_2920(void* object, short deleting);
extern "C" void* fn_101_29AC(void* object, short deleting);
extern "C" void* fn_101_2A38(void* object, short deleting);
void operator delete(void*);

extern "C" void* fn_101_2274(void* object, short deleting) {
    short memberDeleting = -1;
    if (object != 0) {
        fn_101_234C(static_cast<unsigned char*>(object) + 0x14C0, memberDeleting);
        fn_101_2510(static_cast<unsigned char*>(object) + 0x139C, memberDeleting);
        fn_101_25D8(static_cast<unsigned char*>(object) + 0x1270, memberDeleting);
        fn_101_2664(static_cast<unsigned char*>(object) + 0x1144, memberDeleting);
        fn_101_26F0(static_cast<unsigned char*>(object) + 0x1018, memberDeleting);
        fn_101_277C(static_cast<unsigned char*>(object) + 0xEEC, memberDeleting);
        fn_101_2808(static_cast<unsigned char*>(object) + 0xDC0, memberDeleting);
        fn_101_2894(static_cast<unsigned char*>(object) + 0xC94, memberDeleting);
        fn_101_2920(static_cast<unsigned char*>(object) + 0xB68, memberDeleting);
        fn_101_29AC(static_cast<unsigned char*>(object) + 0xA3C, memberDeleting);
        fn_101_2A38(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}