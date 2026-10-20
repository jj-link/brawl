#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_27_93100(void*, short);
void* fn_98_31CC(void*, short);
void* fn_27_19F4C4(void*, short);
void* fn_27_1A55B0(void*, short);
}

extern "C" void* fn_98_3144(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_27_93100(members + 0x22AAC, memberDeleting);
        fn_98_31CC(members + 0x7C, memberDeleting);
        fn_27_19F4C4(members + 0x20, memberDeleting);
        fn_27_1A55B0(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
