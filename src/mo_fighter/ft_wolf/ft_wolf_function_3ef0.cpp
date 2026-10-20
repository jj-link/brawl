#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A262C(void*, short);
extern "C" void* fn_125_3F78(void*, short);
extern "C" void* fn_125_3FB8(void*, short);

extern "C" void* fn_125_3EF0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        if (storage + 0x24 != 0) {
            fn_27_1A262C(storage + 0x34, -1);
            fn_125_3F78(storage + 0x24, 0);
        }
        fn_125_3FB8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
