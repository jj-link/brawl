#pragma force_active on
extern "C" {
void* fn_92_2204(void*, short);
void* fn_92_22A0(void*, short);
void* fn_92_22E0(void*, short);
void* fn_27_C7770(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_92_2634(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_92_2204(members + 0xDC, memberDeleting);
        fn_92_22A0(members + 0xC0, memberDeleting);
        fn_92_22E0(members + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
