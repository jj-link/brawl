#pragma force_active on
void operator delete(void*);
extern "C" void* fn_110_B09C(void* object, short deleting);
extern "C" void fn_110_AF64(void* object, short flag);

extern "C" void* fn_110_B0FC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_110_B09C(storage + 0xEC, -1);
        if (object != 0) {
            fn_110_AF64(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
