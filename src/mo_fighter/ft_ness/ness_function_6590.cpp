#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_101_5F1C(void*, short);
void* fn_101_6600(void*, short);
}

extern "C" void* fn_101_6590(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_101_5F1C(members + 0xC4B0, memberDeleting);
        fn_101_6600(members + 0x4, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
