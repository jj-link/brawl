#pragma force_active on
void operator delete(void*);
extern "C" void* fn_94_D964(void* object, short deleting);
extern "C" void fn_94_D830(void* object, short deleting);

extern "C" void* fn_94_D9C4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_94_D964(storage + 0x1C8, -1);
        if (object != 0) {
            fn_94_D830(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
