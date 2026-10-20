#pragma force_active on
extern "C" void* fn_27_1A262C(void*, short);
extern "C" void* fn_121_4294(void* p, short size);
extern "C" void* fn_121_41B8(void* object, short deleting);

extern "C" void* fn_121_65C4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        if (storage + 0x24 != 0) {
            fn_27_1A262C(storage + 0x34, -1);
            fn_121_4294(storage + 0x24, 0);
        }
        fn_121_41B8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
