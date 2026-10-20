#pragma force_active on
extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_27_21038(void*, short);
extern "C" void* fn_112_3BE4(void*, short);
extern "C" void* fn_112_3C40(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_112_1591C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_13C90(storage + 0xd8, -1);
        fn_27_21038(storage + 0xc4, -1);
        fn_112_3BE4(storage + 0x88, -1);
        fn_112_3C40(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
