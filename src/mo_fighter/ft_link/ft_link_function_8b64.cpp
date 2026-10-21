#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_93_62F8(void* object, short flag);
void* fn_93_62B8(void* p, short flag);
void* fn_93_6394(void* object, short count);
void* fn_93_8B08(void* self, short flag);
void* fn_27_1A5CCC(void* ptr, short size);
}

extern "C" void* fn_93_8B64(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_93_62F8(members + 0x9c4, memberDeleting);
        fn_93_62B8(members + 0x9a8, memberDeleting);
        fn_93_6394(members + 0x8fc, memberDeleting);
        fn_93_8B08(members + 0x47c, memberDeleting);
        if (object != 0) {
            fn_27_1A5CCC(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
