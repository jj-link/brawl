#pragma force_active on
void operator delete(void*);
extern "C" void* fn_115_17A24(void* object, short deleting);
extern "C" void* fn_115_17954(void* object, short deleting);

extern "C" void* fn_115_17A84(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_115_17A24(storage + 0x64, -1);
        if (object != 0) {
            fn_115_17954(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
