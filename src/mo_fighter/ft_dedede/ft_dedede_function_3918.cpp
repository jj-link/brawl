#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_117_38B8(void*, short);
void* fn_117_3984(void*, short);
}

extern "C" void* fn_117_3918(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_117_38B8(storage + 0x3F88, memberDeleting);
        fn_117_3984(storage + 0x4, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
