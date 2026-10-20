#pragma force_active on
extern "C" {
void* fn_96_8460(void* object, short deleting);
void* fn_27_1DBB60(void* object, short deleting);
void* fn_96_2A860(void* object, short deleting);
void* fn_27_1D81C8(void* object, short flag);
}

void operator delete(void*);

extern "C" void* fn_96_2A7D8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_96_8460(members + 0x2088, memberDeleting);
        fn_27_1DBB60(members + 0x2050, memberDeleting);
        fn_96_2A860(members + 0xcc, memberDeleting);
        fn_27_1D81C8(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
