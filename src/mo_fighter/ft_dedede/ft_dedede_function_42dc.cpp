#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_117_3B84(void*, short);
void* fn_117_4348(void*, short);
}

extern "C" void* fn_117_42DC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_117_3B84(storage + 0x27D0, memberDeleting);
        fn_117_4348(storage + 4, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
