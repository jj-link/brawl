#pragma force_active on
extern "C" void* fn_94_D1DC(void* object, short deleting);
extern "C" void fn_94_D30C(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_D36C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_94_D30C(storage + 0x94, -1);
        if (object != 0) {
            fn_94_D1DC(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
