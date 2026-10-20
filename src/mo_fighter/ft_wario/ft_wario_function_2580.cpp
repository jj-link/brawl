#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_110_2268(void*, short);
void* fn_110_2304(void*, short);
void* fn_110_2344(void*, short);
void* fn_27_C7770(void*, short);
}

extern "C" void* fn_110_2580(void* object, short n) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_110_2268(static_cast<unsigned char*>(object) + 0xdc, memberDeleting);
        fn_110_2304(static_cast<unsigned char*>(object) + 0xc0, memberDeleting);
        fn_110_2344(static_cast<unsigned char*>(object) + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (n > 0) {
            operator delete(object);
        }
    }
    return object;
}
