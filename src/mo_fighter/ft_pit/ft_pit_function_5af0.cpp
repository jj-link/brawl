#pragma force_active on
extern "C" void* fn_112_48A8(void*, short);
extern "C" void* fn_112_492C(void*, short);
extern "C" void* fn_112_5B8C(void*, short);
extern "C" void* fn_112_5BE8(void*, short);
extern "C" void* fn_112_6600(void*, short);
extern "C" void* fn_27_C74E8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_112_5AF0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_112_48A8(storage + 0xDD4, -1);
        fn_112_492C(storage + 0xDC0, -1);
        fn_112_5B8C(storage + 0x930, -1);
        fn_112_5BE8(storage + 0xBC, -1);
        fn_112_6600(storage + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
