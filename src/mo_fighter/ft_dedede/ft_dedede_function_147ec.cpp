void operator delete(void*);

extern "C" {
void* fn_27_97968(void*, short);
void* fn_27_1CCCC(void*, short);
void* fn_117_3150(void*, short);
void* fn_27_CBF58(void*, short);
}

extern "C" void* fn_117_147EC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_27_97968(members + 0x58, memberDeleting);
        fn_27_1CCCC(members + 0x48, memberDeleting);
        fn_117_3150(members + 0x3C, memberDeleting);
        if (object != 0) {
            fn_27_CBF58(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
