#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_106_1F40(void*, short);
void* fn_106_1EE4(void*, short);
}

extern "C" void* fn_106_3320(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short memberDeleting = 0;
        fn_106_1F40(storage + 0x20, memberDeleting);
        if (object != 0) {
            fn_106_1EE4(storage + 0x8, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
