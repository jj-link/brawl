#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_126_2000(void* self, short flags);
void* fn_126_209C(void* ptr, short count);
void* fn_126_20DC(void* object, short deleting);
void* fn_27_C7770(void* self, short flags);
}

extern "C" void* fn_126_23A4(void* object, short deleting) {
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
