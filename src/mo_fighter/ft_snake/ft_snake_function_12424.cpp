#pragma force_active on
extern "C" void* fn_122_123C4(void* object, short deleting);
extern "C" void* fn_122_12294(void* object, short deleting);
void operator delete(void*);

extern "C" void* fn_122_12424(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_122_123C4(storage + 0x94, -1);
        if (object != 0) {
            fn_122_12294(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
