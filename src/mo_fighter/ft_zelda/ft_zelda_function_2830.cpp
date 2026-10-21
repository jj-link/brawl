#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_104_21D0(void*, short);
void* fn_104_226C(void*, short);
void* fn_104_22AC(void*, short);
void* fn_104_28C8(void*, short);
void* fn_27_1A5CCC(void*, short);

void* fn_104_2830(void* object, short deleting);
}

void* fn_104_2830(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_104_21D0(members + 0x9C4, memberDeleting);
        fn_104_226C(members + 0x9A8, memberDeleting);
        fn_104_22AC(members + 0x8FC, memberDeleting);
        fn_104_28C8(members + 0x47C, memberDeleting);
        if (object != 0) {
            fn_27_1A5CCC(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
