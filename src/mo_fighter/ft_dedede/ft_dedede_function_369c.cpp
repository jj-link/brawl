#pragma force_active on
void operator delete(void*);
extern "C" void* fn_117_3718(void*, short);
extern "C" void* fn_117_37D8(void*, short);

extern "C" void* fn_117_369C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_117_3718(storage + 0x372e4, -1);
        if (object != 0) {
            fn_117_37D8(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
