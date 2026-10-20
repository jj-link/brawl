#pragma force_active on
extern "C" void fn_108_D32C(void* object, short deleting);
extern "C" void fn_108_D1F8(void* object, short deleting);
extern "C" void __dl__FPv(void*);

void operator delete(void*);

extern "C" void* fn_108_D38C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_108_D32C(storage + 0x1C8, -1);
        if (object != 0) {
            fn_108_D1F8(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
