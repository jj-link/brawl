#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A1E70(void*, short);
extern "C" void fn_120_4048(void*, short);

extern "C" void* fn_120_3FD0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A1E70(storage + 0x4B8, -1);
        if (object != 0) {
            fn_120_4048(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
