#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_92_20A0(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_92_2958(void*, short);
}

extern "C" void* fn_92_201C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_92_20A0(members + 0x107CC, memberDeleting);
        fn_27_C74E8(members + 0x107BC, memberDeleting);
        fn_92_2958(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
