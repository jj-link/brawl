#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_101_24B4(void*, short);
void* fn_101_23D8(void*, short);
}

extern "C" void __dl__FPv(void*);

extern "C" void* fn_101_3BA8(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_101_24B4(static_cast<unsigned char*>(object) + 0x50, memberDeleting);
        fn_101_23D8(object, memberDeleting);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
