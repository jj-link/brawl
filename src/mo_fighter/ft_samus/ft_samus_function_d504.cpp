#pragma force_active on
extern "C" void* fn_94_D4A4(void*, short);
extern "C" void* fn_94_D36C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_D504(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_94_D4A4(storage + 0xEC, -1);
        if (object != 0) {
            fn_94_D36C(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
