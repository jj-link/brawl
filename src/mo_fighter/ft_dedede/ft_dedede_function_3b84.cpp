#pragma force_active on
void operator delete(void*);

extern "C" void* fn_117_1F234(void*, short);

extern "C" void* fn_117_3B84(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_117_1F234(storage + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
