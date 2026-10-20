#pragma force_active on
void operator delete(void*);
extern "C" void* fn_119_AD70(void* object, short deleting);
extern "C" void* fn_119_AC40(void* object, short deleting);

extern "C" void* fn_119_ADD0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_119_AD70(storage + 0x94, -1);
        if (object != 0) {
            fn_119_AC40(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
