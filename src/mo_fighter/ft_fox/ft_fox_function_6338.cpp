#pragma force_active on
void operator delete(void*);
extern "C" void* fn_97_1FCC(void* ptr, short count);
extern "C" void* fn_97_4E58(void* object, short deleting);

extern "C" void* fn_97_6338(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_97_1FCC(storage + 0x20, 0);
        fn_97_4E58(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
