#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_117_CB04(void*, short);
void* fn_117_C9D0(void*, short);
}

extern "C" void* fn_117_CB64(void* object, short deleting) {
    if (object != 0) {
        fn_117_CB04(static_cast<unsigned char*>(object) + 0x134, -1);
        if (object != 0) {
            fn_117_C9D0(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
