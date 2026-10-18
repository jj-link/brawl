#pragma force_active on
void operator delete(void*);

extern "C" {
void fn_27_57BA0(void*, short);
void fn_119_1F2C(void*, short);
void fn_119_1F88(void*, short);
}

extern "C" void* fn_119_1EAC(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        if (storage + 0x20 != 0) {
            fn_27_57BA0(storage + 0x20, 0);
        }
        fn_119_1F2C(storage + 0x14, 0);
        fn_119_1F88(storage + 8, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
