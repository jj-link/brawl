#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_112_21EC(void*, short);
void* fn_112_2288(void*, short);
void* fn_112_22C8(void*, short);
void* fn_112_28E4(void*, short);
void fn_27_1A61E0(void*, short);
}

extern "C" void* fn_112_284C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_112_21EC(members + 0x9ec, memberDeleting);
        fn_112_2288(members + 0x9d0, memberDeleting);
        fn_112_22C8(members + 0x924, memberDeleting);
        fn_112_28E4(members + 0x490, memberDeleting);
        if (object != 0) {
            fn_27_1A61E0(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
