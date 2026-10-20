#pragma force_active on
extern "C" void fn_27_1A18A0(void*, short);
extern "C" void fn_122_9324(void*, short);

extern "C" void* fn_122_92AC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A18A0(storage + 0x354, -1);
        if (object != 0) {
            fn_122_9324(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
