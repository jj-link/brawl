#pragma force_active on
extern "C" void fn_27_1A1E70(void*, short);
extern "C" void fn_92_5438(void*, short);
void operator delete(void*);

extern "C" void* fn_92_53C0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A1E70(storage + 0x4B8, -1);
        if (object != 0) {
            fn_92_5438(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
