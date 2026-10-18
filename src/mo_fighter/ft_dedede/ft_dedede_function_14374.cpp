#pragma force_active on
void operator delete(void*);
extern "C" void* fn_117_44C8(void*, short);

extern "C" void* fn_117_14374(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_117_44C8(storage + 0x14, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
