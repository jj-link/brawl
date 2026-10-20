#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A262C(void*, short);
extern "C" void* fn_95_41DC(void*, short);
extern "C" void* fn_95_421C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_95_4154(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        if (storage + 0x24 != 0) {
            fn_27_1A262C(storage + 0x34, -1);
            fn_95_41DC(storage + 0x24, 0);
        }
        fn_95_421C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
