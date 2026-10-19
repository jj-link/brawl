#pragma force_active on
void operator delete(void*);
extern "C" void* fn_97_4868(void*, short);
extern "C" void* fn_97_5140(void*, short);

extern "C" void* fn_97_50D4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_97_4868(storage + 0x6488, -1);
        fn_97_5140(storage + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
