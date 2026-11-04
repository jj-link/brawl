#pragma force_active on
void operator delete(void*);

extern "C" void* fn_98_20AC(void* object, short deleting);
extern "C" void* fn_98_2270(void* object, short deleting);
extern "C" void* fn_98_2338(void* object, short deleting);
extern "C" void* fn_98_23C4(void* object, short deleting);
extern "C" void* fn_98_2450(void* object, short deleting);
extern "C" void* fn_98_24DC(void* object, short deleting);
extern "C" void* fn_98_2568(void* object, short deleting);
extern "C" void* fn_98_25F4(void* object, short deleting);
extern "C" void* fn_98_2680(void* object, short deleting);
extern "C" void* fn_98_270C(void* object, short deleting);
extern "C" void* fn_98_2798(void* object, short deleting);

extern "C" void* fn_98_1FD4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_98_20AC(members + 0x14B8, memberDeleting);
        fn_98_2270(members + 0x1394, memberDeleting);
        fn_98_2338(members + 0x1268, memberDeleting);
        fn_98_23C4(members + 0x113C, memberDeleting);
        fn_98_2450(members + 0x1010, memberDeleting);
        fn_98_24DC(members + 0xEE4, memberDeleting);
        fn_98_2568(members + 0xDB8, memberDeleting);
        fn_98_25F4(members + 0xC8C, memberDeleting);
        fn_98_2680(members + 0xB60, memberDeleting);
        fn_98_270C(members + 0xA34, memberDeleting);
        fn_98_2798(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}