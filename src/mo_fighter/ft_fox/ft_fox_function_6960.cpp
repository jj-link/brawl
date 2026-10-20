#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_1A18A0(void* object, short deleting);
extern "C" void fn_97_69D8(void* object, short flag);

extern "C" void* fn_97_6960(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A18A0(storage + 0x354, -1);
        if (object != 0) {
            fn_97_69D8(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
