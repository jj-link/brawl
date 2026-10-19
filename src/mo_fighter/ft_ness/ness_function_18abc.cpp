#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_101_5994(void*, short);
void* fn_101_18B28(void*, short);
}

extern "C" void* fn_101_18ABC(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_101_5994(static_cast<unsigned char*>(object) + 0x7E18, memberDeleting);
        fn_101_18B28(static_cast<unsigned char*>(object) + 0x4, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
