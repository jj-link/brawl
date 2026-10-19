#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_117_3B84(void*, short);
void* fn_117_3E14(void*, short);
}

extern "C" void* fn_117_3DA4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_117_3B84(members + 0x20530, memberDeleting);
        fn_117_3E14(members + 0x4, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
