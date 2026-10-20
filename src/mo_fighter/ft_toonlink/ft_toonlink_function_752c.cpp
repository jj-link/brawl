#pragma force_active on
void operator delete(void*);
extern "C" void* fn_121_74CC(void* object, short deleting);
extern "C" void* fn_121_73FC(void* object, short deleting);

extern "C" void* fn_121_752C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_121_74CC(storage + 0x4F2C, -1);
        if (object != 0) {
            fn_121_73FC(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
