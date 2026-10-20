#pragma force_active on
void operator delete(void*);
extern "C" void fn_109_51B0(void* object, short deleting);
extern "C" void* fn_27_1A15B8(void* object, short deleting);

extern "C" void* fn_109_5138(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A15B8(storage + 0x2FC, -1);
        if (object != 0) {
            fn_109_51B0(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
