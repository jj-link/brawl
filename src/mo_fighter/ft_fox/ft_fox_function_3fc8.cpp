#pragma force_active on
extern "C" void* fn_27_1A262C(void*, short);
extern "C" void* fn_97_4050(void*, short);
extern "C" void* fn_97_4090(void*, short);

void operator delete(void*);

extern "C" void* fn_97_3FC8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        if (storage + 0x24 != 0) {
            fn_27_1A262C(storage + 0x34, -1);
            fn_97_4050(storage + 0x24, 0);
        }
        fn_97_4090(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
