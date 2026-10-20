#pragma force_active on
void operator delete(void*);
extern "C" void* fn_120_BAB8(void* object, short deleting);
extern "C" void fn_120_B984(void* object, short deleting);

extern "C" void* fn_120_BB18(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_120_BAB8(storage + 0x1C8, -1);
        if (object != 0) {
            fn_120_B984(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
