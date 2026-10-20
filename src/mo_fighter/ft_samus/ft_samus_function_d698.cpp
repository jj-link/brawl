#pragma force_active on
void operator delete(void*);
extern "C" void* fn_94_D638(void* object, short deleting);
extern "C" void fn_94_D504(void* object, short deleting);

extern "C" void* fn_94_D698(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_94_D638(storage + 0x134, -1);
        if (object != 0) {
            fn_94_D504(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
