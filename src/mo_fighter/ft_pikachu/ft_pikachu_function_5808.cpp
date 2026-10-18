#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_98_418C(void*, short);
void* fn_98_4210(void*, short);
void* fn_98_58A4(void*, short);
void* fn_98_5900(void*, short);
void* fn_98_6318(void*, short);
void* fn_27_C74E8(void*, short);
}

extern "C" void* fn_98_5808(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_98_418C(members + 0xDD0, memberDeleting);
        fn_98_4210(members + 0xDBC, memberDeleting);
        fn_98_58A4(members + 0x930, memberDeleting);
        fn_98_5900(members + 0xBC, memberDeleting);
        fn_98_6318(members + 0x10, memberDeleting);
        fn_27_C74E8(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
