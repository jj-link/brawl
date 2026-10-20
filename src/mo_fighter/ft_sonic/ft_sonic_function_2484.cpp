#pragma force_active on
extern "C" {
void* fn_123_216C(void* object, short deleteFlag);
void* fn_123_2208(void* ptr, short count);
void* fn_123_2248(void* object, short deleting);
void* fn_27_C7770(void* object, short deleting);
void __dl__FPv(void*);
}

extern "C" void* fn_123_2484(void* object, short deleting) {
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
