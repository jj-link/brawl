#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_126_2000(void*, short);
void* fn_126_209C(void*, short);
void* fn_126_20DC(void*, short);
void* fn_27_C7770(void*, short);
}

extern "C" void* fn_126_2200(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_126_2000(members + 0xdc, memberDeleting);
        fn_126_209C(members + 0xc0, memberDeleting);
        fn_126_20DC(members + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
