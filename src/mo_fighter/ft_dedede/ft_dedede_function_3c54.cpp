#pragma force_active on
void operator delete(void*);
extern "C" void* fn_117_3B84(void*, short);
extern "C" void* fn_117_3CC4(void*, short);

extern "C" void* fn_117_3C54(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_117_3B84(storage + 0x27C88, -1);
        fn_117_3CC4(storage + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
