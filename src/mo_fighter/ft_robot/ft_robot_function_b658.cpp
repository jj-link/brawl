#pragma force_active on
void operator delete(void*);
extern "C" void fn_120_B5F8(void* object, short deleting);
extern "C" void fn_120_B4C0(void* object, short deleting);

extern "C" void* fn_120_B658(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_120_B5F8(storage + 0xEC, -1);
        if (object != 0) {
            fn_120_B4C0(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
