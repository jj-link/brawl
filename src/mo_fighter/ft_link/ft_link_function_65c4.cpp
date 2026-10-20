#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A262C(void*, short);
extern "C" void* fn_93_4294(void*, short);
extern "C" void fn_93_41B8(void*, short);

extern "C" void* fn_93_65C4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        if (storage + 0x24 != 0) {
            fn_27_1A262C(storage + 0x34, -1);
            fn_93_4294(storage + 0x24, 0);
        }
        fn_93_41B8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
