#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_105_218C(void*, short);
void* fn_105_2228(void*, short);
void* fn_105_2268(void*, short);
void* fn_105_2884(void*, short);
void fn_27_1A61E0(void*, short);
}

extern "C" void* fn_105_27EC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_105_218C(members + 0x9EC, memberDeleting);
        fn_105_2228(members + 0x9D0, memberDeleting);
        fn_105_2268(members + 0x924, memberDeleting);
        fn_105_2884(members + 0x490, memberDeleting);
        if (object != 0) {
            fn_27_1A61E0(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
