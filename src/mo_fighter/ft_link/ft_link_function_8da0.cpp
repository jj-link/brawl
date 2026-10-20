#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_93_62F8(void* object, short flag);
void* fn_93_62B8(void* p, short flag);
void* fn_93_6394(void* object, short count);
void* fn_27_C7770(void* object, short deleting);
}

extern "C" void* fn_93_8DA0(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_93_62F8((char*)object + 0xdc, memberDeleting);
        fn_93_62B8((char*)object + 0xc0, memberDeleting);
        fn_93_6394((char*)object + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
