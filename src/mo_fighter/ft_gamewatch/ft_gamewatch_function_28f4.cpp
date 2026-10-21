#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_107_2294(void*, short);
void* fn_107_2330(void*, short);
void* fn_107_2370(void*, short);
void* fn_107_298C(void*, short);
void fn_27_1A6C08(void*, short);
}

extern "C" void* fn_107_28F4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_107_2294(members + 0xAAC, memberDeleting);
        fn_107_2330(members + 0xA90, memberDeleting);
        fn_107_2370(members + 0x9E4, memberDeleting);
        fn_107_298C(members + 0x4F0, memberDeleting);
        if (object != 0) {
            fn_27_1A6C08(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
