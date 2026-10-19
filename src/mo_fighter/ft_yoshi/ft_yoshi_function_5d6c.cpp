#pragma force_active on
void operator delete(void*);
extern "C" void* fn_95_5DD8(void*, short);
extern "C" void* fn_95_60D8(void*, short);

extern "C" void* fn_95_5D6C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_95_5DD8(storage + 0x1fe8, -1);
        fn_95_60D8(storage + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
