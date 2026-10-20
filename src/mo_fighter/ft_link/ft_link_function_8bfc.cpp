#pragma force_active on
extern "C" {
void* fn_93_62F8(void*, short);
void* fn_93_62B8(void*, short);
void* fn_93_6394(void*, short);
void* fn_27_C7770(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_93_8BFC(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_93_62F8(members + 0xDC, memberDeleting);
        fn_93_62B8(members + 0xC0, memberDeleting);
        fn_93_6394(members + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
