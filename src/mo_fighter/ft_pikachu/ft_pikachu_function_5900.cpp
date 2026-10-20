#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_98_42F8(void*, short);
void* fn_98_5978(void*, short);
void* fn_27_19E99C(void*, short);
}

extern "C" void* fn_98_5900(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_98_42F8(members + 0x85C, memberDeleting);
        fn_98_5978(members + 0x19C, memberDeleting);
        fn_27_19E99C(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
