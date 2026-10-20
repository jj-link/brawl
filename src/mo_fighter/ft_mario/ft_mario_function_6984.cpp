#pragma force_active on
extern "C" {
void* fn_91_2C9C(void*, short);
void* fn_27_D2AA4(void*, short);
void* fn_27_CD934(void*, short);

void* fn_91_6984(void* object, short deleting) {
    if (object != 0) {
        fn_91_2C9C(static_cast<unsigned char*>(object) + 0x6c, static_cast<short>(-1));
        if (static_cast<unsigned char*>(object) + 0x20 != 0 && static_cast<unsigned char*>(object) + 0x20 != 0 && static_cast<unsigned char*>(object) + 0x20 != 0) {
            fn_27_D2AA4(static_cast<unsigned char*>(object) + 0x20, static_cast<short>(-1));
        }
        fn_27_CD934(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
