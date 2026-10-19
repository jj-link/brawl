#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_117_3B84(void*, short);
void* fn_117_3EF4(void*, short);
}

extern "C" void* fn_117_3E84(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        unsigned char* outer = storage + 0x20000;
        fn_117_3B84(outer - 0x4A60, memberDeleting);
        fn_117_3EF4(storage + 0x4, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
