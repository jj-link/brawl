#pragma force_active on
extern "C" void* fn_116_3408(void*, short);
extern "C" void* fn_116_44AC(void*, short);
void operator delete(void*);

extern "C" void* fn_116_4440(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_116_3408(storage + 0x165c, -1);
        fn_116_44AC(storage + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
