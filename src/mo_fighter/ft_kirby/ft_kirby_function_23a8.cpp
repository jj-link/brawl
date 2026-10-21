#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_96_234C(void*, short);
void* fn_96_22F0(void*, short);
void* fn_96_2294(void*, short);
void* fn_96_2238(void*, short);
void* fn_96_21DC(void*, short);
void* fn_96_2180(void*, short);
void* fn_96_2124(void*, short);
void* fn_96_2080(void*, short);
}

extern "C" void* fn_96_23A8(void* object, short deleting) {
    if (object != 0) {
        fn_96_234C((unsigned char*)object + 0x84, -1);
        fn_96_22F0((unsigned char*)object + 0x70, -1);
        fn_96_2294((unsigned char*)object + 0x5C, -1);
        fn_96_2238((unsigned char*)object + 0x48, -1);
        fn_96_21DC((unsigned char*)object + 0x34, -1);
        fn_96_2180((unsigned char*)object + 0x20, -1);
        fn_96_2124((unsigned char*)object + 0x08, -1);
        fn_96_2080(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
