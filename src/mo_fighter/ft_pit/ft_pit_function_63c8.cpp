#pragma force_active on
extern "C" void* fn_27_1A1B88(void* member, short deleteFlag);
extern "C" void* fn_112_6440(void* object, short flag);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_112_63C8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A1B88(storage + 0xF0, -1);
        if (object != 0) {
            fn_112_6440(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
