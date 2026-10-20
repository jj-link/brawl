#pragma force_active on
void operator delete(void*);
extern "C" void* fn_115_1665C(void*, short);
extern "C" void* fn_115_1B2A8(void*, short);
extern "C" void* fn_115_1B21C(void*, short);
extern "C" void* fn_115_1B190(void*, short);
extern "C" void* fn_115_1B104(void*, short);

extern "C" void* fn_115_1B334(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_115_1665C(storage + 0x4B0, -1);
        fn_115_1B2A8(storage + 0x384, -1);
        fn_115_1B21C(storage + 0x258, -1);
        fn_115_1B190(storage + 0x12C, -1);
        fn_115_1B104(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
