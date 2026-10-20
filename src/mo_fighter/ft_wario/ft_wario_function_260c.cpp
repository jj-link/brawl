#pragma force_active on
extern "C" void* fn_110_2268(void*, short);
extern "C" void* fn_110_2304(void*, short);
extern "C" void* fn_110_2344(void*, short);
extern "C" void* fn_27_C7770(void*, short);

extern "C" void* fn_110_260C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_110_2268(members + 0xdc, memberDeleting);
        fn_110_2304(members + 0xc0, memberDeleting);
        fn_110_2344(members + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
