#pragma force_active on
extern "C" void fn_27_1A1FE4(void* object, short deleting);
extern "C" void fn_122_9504(void* object, short deleting);
void operator delete(void*);

extern "C" void* fn_122_948C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A1FE4(storage + 0x244, -1);
        if (object != 0) {
            fn_122_9504(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
