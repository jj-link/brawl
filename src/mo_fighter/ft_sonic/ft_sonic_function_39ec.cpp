#pragma force_active on
void operator delete(void*);
extern "C" void* fn_123_2248(void*, short);
extern "C" void* fn_123_216C(void*, short);

extern "C" void* fn_123_39EC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_123_2248(storage + 0x50, -1);
        fn_123_216C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
