#pragma force_active on
extern "C" {
void* fn_104_21D0(void* object, short deleting);
void* fn_104_226C(void* p, short flag);
void* fn_104_22AC(void* object, short count);
void* fn_27_C7770(void*, short);
}

extern "C" void* fn_104_50D8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_104_21D0(members + 0xDC, memberDeleting);
        fn_104_226C(members + 0xC0, memberDeleting);
        fn_104_22AC(members + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
