#pragma force_active on
void operator delete(void*);
extern "C" void* fn_107_2370(void*, short);
extern "C" void* fn_107_2294(void*, short);

extern "C" void* fn_107_3A20(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_107_2370(storage + 0x50, -1);
        fn_107_2294(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
