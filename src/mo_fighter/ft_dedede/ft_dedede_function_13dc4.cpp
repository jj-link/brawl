#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_117_13D4C(void*, short);
}

extern "C" void* fn_117_13DC4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_27_13C90(members + 0x9C, memberDeleting);
        fn_27_21038(members + 0x88, memberDeleting);
        fn_117_13D4C(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
