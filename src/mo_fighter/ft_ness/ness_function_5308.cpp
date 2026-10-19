#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_101_5378(void*, short);
void* fn_101_5DD4(void*, short);
}

extern "C" void* fn_101_5308(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_101_5378(static_cast<unsigned char*>(object) + 0xDE20, memberDeleting);
        fn_101_5DD4(static_cast<unsigned char*>(object) + 4, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
