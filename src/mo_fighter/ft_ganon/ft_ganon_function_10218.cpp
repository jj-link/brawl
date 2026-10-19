#pragma force_active on
void operator delete(void*);
extern "C" void* fn_109_2230(void*, short);
extern "C" void* fn_109_2154(void*, short);

extern "C" void* fn_109_10218(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_109_2230(storage + 0x50, -1);
        fn_109_2154(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
