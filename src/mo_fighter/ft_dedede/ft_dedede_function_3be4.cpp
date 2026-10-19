#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_117_3B84(void*, short);
void* fn_117_3C54(void*, short);
}

extern "C" void* fn_117_3BE4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_117_3B84(storage + 0x2A450, memberDeleting);
        fn_117_3C54(storage + 0x4, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
