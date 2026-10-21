#pragma force_active on

extern "C" {
void* fn_114_3E98(void*, short);
void* fn_27_1A241C(void*, short);
void* fn_114_3ED8(void*, short);
void* fn_114_3F18(void*, short);
}

void operator delete(void*);

extern "C" void* fn_114_3E04(void* object, short deleting) {
    if (object != 0) {
        short flag = -1;
        fn_114_3E98(static_cast<unsigned char*>(object) + 0xB0, flag);
        if ((int)object + 0x30 != 0) {
            fn_27_1A241C(static_cast<unsigned char*>(object) + 0x40, flag);
            fn_114_3ED8(static_cast<unsigned char*>(object) + 0x30, 0);
        }
        fn_114_3F18(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
