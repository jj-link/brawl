#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_96_6B10(void*, short);
void* fn_96_6AD0(void*, short);
void* fn_96_6BAC(void*, short);
void* fn_27_C7770(void*, short);
}

extern "C" void* fn_96_7B8C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_96_6B10(members + 0xdc, memberDeleting);
        fn_96_6AD0(members + 0xc0, memberDeleting);
        fn_96_6BAC(members + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
