#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_101_23D8(void*, short);
void* fn_101_2474(void*, short);
void* fn_101_24B4(void*, short);
void* fn_27_C7770(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_101_6CAC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_101_23D8(storage + 0xDC, memberDeleting);
        fn_101_2474(storage + 0xC0, memberDeleting);
        fn_101_24B4(storage + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
