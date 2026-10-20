#pragma force_active on
extern "C" void* fn_123_216C(void*, short);
extern "C" void* fn_123_2208(void*, short);
extern "C" void* fn_123_2248(void*, short);
extern "C" void* fn_27_C7770(void*, short);

extern "C" void* fn_123_2510(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_123_216C(members + 0xdc, memberDeleting);
        fn_123_2208(members + 0xc0, memberDeleting);
        fn_123_2248(members + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
