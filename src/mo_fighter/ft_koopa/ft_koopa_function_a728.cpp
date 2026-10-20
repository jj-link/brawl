#pragma force_active on
void operator delete(void*);
extern "C" void* fn_102_A6C8(void* object, short deleting);
extern "C" void* fn_102_A598(void* object, short deleting);

extern "C" void* fn_102_A728(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_102_A6C8(storage + 0x94, -1);
        if (object != 0) {
            fn_102_A598(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
