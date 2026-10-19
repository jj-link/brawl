#pragma force_active on
extern "C" void* fn_107_2438(void* object, short deleting);
extern "C" void* fn_107_2294(void* object, short deleting);
void operator delete(void*);

extern "C" void* fn_107_23CC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_107_2438(storage + 0x50, -1);
        fn_107_2294(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
