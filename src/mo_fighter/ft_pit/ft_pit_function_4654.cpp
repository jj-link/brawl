#pragma force_active on
extern "C" {
void* fn_112_21EC(void*, short);
void* fn_112_2288(void*, short);
void* fn_112_22C8(void*, short);
void* fn_27_C7770(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_112_4654(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_112_21EC(members + 0xdc, memberDeleting);
        fn_112_2288(members + 0xc0, memberDeleting);
        fn_112_22C8(members + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
