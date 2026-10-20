#pragma force_active on
void operator delete(void*);
extern "C" void* fn_97_D4BC(void* object, short deleting);
extern "C" void fn_97_D388(void* object, short deleting);

extern "C" void* fn_97_D51C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_97_D4BC(storage + 0x1C8, -1);
        if (object != 0) {
            fn_97_D388(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
