#pragma force_active on
void operator delete(void*);
extern "C" void fn_94_1F14(void*, short);
extern "C" void* fn_94_48C8(void*, short);

extern "C" void* fn_94_154D4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_94_1F14(storage + 0x20, 0);
        fn_94_48C8(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
