#pragma force_active on
void operator delete(void*);
extern "C" void* fn_113_ED50(void* object, short deleting);
extern "C" void fn_113_EC1C(void* object, short deleting);

extern "C" void* fn_113_EDB0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_113_ED50(storage + 0x204, -1);
        if (object != 0) {
            fn_113_EC1C(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
