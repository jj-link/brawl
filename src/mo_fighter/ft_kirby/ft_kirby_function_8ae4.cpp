#pragma force_active on
extern "C" {
void* fn_96_84FC(void*, short);
void* fn_27_1A241C(void*, short);
void* fn_96_5FB4(void*, short);
void* fn_96_853C(void*, short);
}

void operator delete(void*);

extern "C" void* fn_96_8AE4(void* object, short deleting) {
    if (object != 0) {
        short flag = -1;
        fn_96_84FC(static_cast<unsigned char*>(object) + 0xB0, flag);
        if ((int)object + 0x30 != 0) {
            fn_27_1A241C(static_cast<unsigned char*>(object) + 0x40, flag);
            fn_96_5FB4(static_cast<unsigned char*>(object) + 0x30, 0);
        }
        fn_96_853C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
