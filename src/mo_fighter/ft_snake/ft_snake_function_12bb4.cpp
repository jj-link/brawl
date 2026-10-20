#pragma force_active on
void operator delete(void*);
extern "C" void* fn_122_12B54(void* object, short deleting);
extern "C" void fn_122_12A20(void* object, short deleting);

extern "C" void* fn_122_12BB4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_122_12B54(storage + 0x204, -1);
        if (object != 0) {
            fn_122_12A20(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
