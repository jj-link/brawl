#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_27_97968(void*, short);
void* fn_27_1CCCC(void*, short);
void* fn_92_3158(void*, short);
void* fn_92_31B4(void*, short);
void* fn_27_CBF58(void*, short);
}

extern "C" void* fn_92_30C0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_27_97968(members + 0x6C, memberDeleting);
        fn_27_1CCCC(members + 0x5C, memberDeleting);
        fn_92_3158(members + 0x50, memberDeleting);
        fn_92_31B4(members + 0x38, memberDeleting);
        if (object != 0) {
            fn_27_CBF58(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
