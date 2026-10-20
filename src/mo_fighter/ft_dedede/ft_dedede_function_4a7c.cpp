#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_27_1A1E70(void*, short);
void fn_117_4AF4(void*, short);
}

extern "C" void* fn_117_4A7C(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1E70(static_cast<unsigned char*>(object) + 0x4B8, static_cast<short>(-1));
        if (object != 0) {
            fn_117_4AF4(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
