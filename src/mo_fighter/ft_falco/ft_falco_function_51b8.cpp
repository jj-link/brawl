#pragma force_active on
extern "C" void* fn_108_5224(void*, short);
extern "C" void* fn_108_556C(void*, short);
void operator delete(void*);

extern "C" void* fn_108_51B8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_108_5224(storage + 0x1FB0, -1);
        fn_108_556C(storage + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
