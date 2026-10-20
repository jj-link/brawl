#pragma force_active on
extern "C" {
void* fn_112_2088(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_112_2940(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_112_2004(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_112_2088(members + 0x27A80, memberDeleting);
        fn_27_C74E8(members + 0x27A70, memberDeleting);
        fn_112_2940(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
