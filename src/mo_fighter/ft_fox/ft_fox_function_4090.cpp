#pragma force_active on
void operator delete(void*);
extern "C" void* fn_97_1F70(void*, short);
extern "C" void* fn_97_1FCC(void*, short);

extern "C" void* fn_97_4090(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_97_1F70(storage + 0x14, 0);
        fn_97_1FCC(storage + 0x8, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
