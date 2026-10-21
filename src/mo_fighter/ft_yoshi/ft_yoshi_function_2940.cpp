#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_95_22E0(void*, short);
void* fn_95_237C(void*, short);
void* fn_95_23BC(void*, short);
void* fn_95_29D8(void*, short);
void* fn_27_1A65F0(void*, short);
}

extern "C" void* fn_95_2940(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_95_22E0(members + 0xa0c, memberDeleting);
        fn_95_237C(members + 0x9f0, memberDeleting);
        fn_95_23BC(members + 0x944, memberDeleting);
        fn_95_29D8(members + 0x4a0, memberDeleting);
        if (object != 0) {
            fn_27_1A65F0(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
