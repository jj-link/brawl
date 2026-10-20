#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_116_2000(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_116_28B8(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_116_1F7C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_116_2000(members + 0x162B4, memberDeleting);
        fn_27_C74E8(members + 0x162A4, memberDeleting);
        fn_116_28B8(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
