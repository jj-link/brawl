#pragma force_active on
extern "C" {
void* fn_96_6B10(void* object, short deleting);
void* fn_96_6AD0(void* p, short size);
void* fn_96_6BAC(void* object, short count);
void* fn_27_C7770(void*, short);
void operator delete(void*);
}

extern "C" void* fn_96_A714(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_96_6B10(static_cast<unsigned char*>(object) + 0xDC, memberDeleting);
        fn_96_6AD0(static_cast<unsigned char*>(object) + 0xC0, memberDeleting);
        fn_96_6BAC(static_cast<unsigned char*>(object) + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
