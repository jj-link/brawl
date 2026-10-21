#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_121_62F8(void*, short);
void* fn_121_62B8(void*, short);
void* fn_121_6394(void*, short);
void* fn_121_8B08(void*, short);
void* fn_27_1A5CCC(void*, short);
}

extern "C" void* fn_121_8B64(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_121_62F8(members + 0x9C4, memberDeleting);
        fn_121_62B8(members + 0x9A8, memberDeleting);
        fn_121_6394(members + 0x8FC, memberDeleting);
        fn_121_8B08(members + 0x47C, memberDeleting);
        if (object != 0) {
            fn_27_1A5CCC(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
