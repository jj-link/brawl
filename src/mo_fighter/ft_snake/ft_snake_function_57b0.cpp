#pragma force_active on
extern "C" {
void* fn_122_3EE4(void*, short);
void* fn_27_1A241C(void*, short);
void* fn_122_3F94(void*, short);
void* fn_122_3FD4(void*, short);
}

void operator delete(void*);

extern "C" void* fn_122_57B0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* p = static_cast<unsigned char*>(object);
        short d = -1;
        fn_122_3EE4(p + 0xB0, d);
        if ((unsigned long)p + 0x30 != 0) {
            fn_27_1A241C(p + 0x40, d);
            fn_122_3F94(p + 0x30, static_cast<short>(0));
        }
        fn_122_3FD4(object, d);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
