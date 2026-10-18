#pragma force_active on
extern "C" {
void* fn_91_4564(void*, short);
void* fn_91_4504(void*, short);
void* fn_91_522C(void*, short);
void* fn_91_51B4(void*, short);
void* fn_91_47B4(void*, short);
void* fn_27_C74E8(void*, short);
void __dl__FPv(void*);

void* fn_91_5288(void* object, short deleting) {
    if (object != 0) {
        fn_91_4564(static_cast<unsigned char*>(object) + 0xdb4, static_cast<short>(-1));
        fn_91_4504(static_cast<unsigned char*>(object) + 0xda0, static_cast<short>(-1));
        fn_91_522C(static_cast<unsigned char*>(object) + 0x930, static_cast<short>(-1));
        fn_91_51B4(static_cast<unsigned char*>(object) + 0xbc, static_cast<short>(-1));
        fn_91_47B4(static_cast<unsigned char*>(object) + 0x10, static_cast<short>(-1));
        fn_27_C74E8(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
