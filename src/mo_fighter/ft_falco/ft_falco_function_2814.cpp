#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_108_21B4(void*, short);
void* fn_108_2250(void*, short);
void* fn_108_2290(void*, short);
void* fn_108_28AC(void*, short);
void fn_27_1A5DD0(void*, short);
}

extern "C" void* fn_108_2814(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_108_21B4(members + 0x9cc, memberDeleting);
        fn_108_2250(members + 0x9b0, memberDeleting);
        fn_108_2290(members + 0x904, memberDeleting);
        fn_108_28AC(members + 0x480, memberDeleting);
        if (object != 0) {
            fn_27_1A5DD0(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
