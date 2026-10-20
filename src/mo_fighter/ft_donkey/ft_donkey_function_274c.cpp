#pragma force_active on
extern "C" void* fn_92_2204(void*, short);
extern "C" void* fn_92_22A0(void*, short);
extern "C" void* fn_92_22E0(void*, short);
extern "C" void* fn_27_C7770(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_274C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short flag = -1;
        fn_92_2204(storage + 0xDC, flag);
        fn_92_22A0(storage + 0xC0, flag);
        fn_92_22E0(storage + 0x14, flag);
        if (object != 0) {
            fn_27_C7770(object, flag);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
