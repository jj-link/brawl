#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_27_B81C4(void*, short);
void* fn_96_9C90(void*, short);
void* fn_27_1982AC(void*, short);
}

extern "C" void* fn_96_9CEC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_27_B81C4(members + 0xF4, memberDeleting);
        fn_96_9C90(members + 0x98, memberDeleting);
        if (object != 0) {
            fn_27_1982AC(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
