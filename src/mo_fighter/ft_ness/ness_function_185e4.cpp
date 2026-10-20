#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_27_93100(void*, short);
void* fn_101_1866C(void*, short);
void* fn_27_19F65C(void*, short);
void* fn_27_1A56B4(void*, short);
}

extern "C" void* fn_101_185E4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_27_93100(members + 0xBDBC, memberDeleting);
        fn_101_1866C(members + 0x90, memberDeleting);
        fn_27_19F65C(members + 0x24, memberDeleting);
        fn_27_1A56B4(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
