#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_116_2164(void*, short);
void* fn_116_2200(void*, short);
void* fn_116_2240(void*, short);
void* fn_27_C7770(void*, short);
}

extern "C" void* fn_116_15A58(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_116_2164(members + 0xDC, memberDeleting);
        fn_116_2200(members + 0xC0, memberDeleting);
        fn_116_2240(members + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
