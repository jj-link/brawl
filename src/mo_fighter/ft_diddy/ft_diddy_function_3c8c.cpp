#pragma force_active on
extern "C" void* fn_115_1EF0(void*, short);
extern "C" void* fn_115_1F4C(void*, short);
void operator delete(void*);

extern "C" void* fn_115_3C8C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_115_1EF0(storage + 0x14, 0);
        fn_115_1F4C(storage + 0x8, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
