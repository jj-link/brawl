#pragma force_active on
void operator delete(void*);
extern "C" void* fn_109_B010(void* object, short deleting);
extern "C" void fn_109_AEDC(void* object, short deleting);

extern "C" void* fn_109_B070(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_109_B010(storage + 0x204, -1);
        if (object != 0) {
            fn_109_AEDC(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
