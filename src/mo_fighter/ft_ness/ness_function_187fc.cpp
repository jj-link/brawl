#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_101_5994(void*, short);
void* fn_101_18ABC(void*, short);
}

extern "C" void* fn_101_187FC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_101_5994(members + 0x9D9C, memberDeleting);
        fn_101_18ABC(members + 0x4, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
