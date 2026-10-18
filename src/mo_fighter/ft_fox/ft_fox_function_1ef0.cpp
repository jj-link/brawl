#pragma force_active on
void operator delete(void*);

extern "C" {
void fn_27_57BA0(void*, short);
void fn_97_1F70(void*, short);
void fn_97_1FCC(void*, short);
}

extern "C" void* fn_97_1EF0(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        if (storage + 0x20 != 0) {
            fn_27_57BA0(storage + 0x20, 0);
        }
        fn_97_1F70(storage + 0x14, 0);
        fn_97_1FCC(storage + 8, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
