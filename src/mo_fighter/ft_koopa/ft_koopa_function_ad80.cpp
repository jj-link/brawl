#pragma force_active on
void operator delete(void*);
extern "C" void* fn_102_AD20(void* object, short deleting);
extern "C" void* fn_102_ABEC(void* object, short deleting);

extern "C" void* fn_102_AD80(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_102_AD20(storage + 0x1C8, -1);
        if (object != 0) {
            fn_102_ABEC(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
