#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_27_97968(void*, short);
void* fn_27_1CCCC(void*, short);
void* fn_107_31F4(void*, short);
void* fn_107_3250(void*, short);
void* fn_27_CBF58(void*, short);
}

extern "C" void* fn_107_315C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_27_97968(members + 0x6c, memberDeleting);
        fn_27_1CCCC(members + 0x5c, memberDeleting);
        fn_107_31F4(members + 0x50, memberDeleting);
        fn_107_3250(members + 0x38, memberDeleting);
        if (object != 0) {
            fn_27_CBF58(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
