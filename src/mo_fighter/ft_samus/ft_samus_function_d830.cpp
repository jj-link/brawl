#pragma force_active on
extern "C" void* fn_94_D698(void* object, short deleting);
extern "C" void* fn_94_D7D0(void* object, short deleting);
void operator delete(void*);

extern "C" void* fn_94_D830(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_94_D7D0(storage + 0x17c, -1);
        if (object != 0) {
            fn_94_D698(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
