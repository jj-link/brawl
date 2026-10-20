#pragma force_active on
void operator delete(void*);
extern "C" void* fn_115_A7D4(void*, short);
extern "C" void* fn_115_4864(void*, short);
extern "C" void* fn_115_48C4(void*, short);

extern "C" void* fn_115_47EC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_115_A7D4(storage + 0xE0, -1);
        fn_115_4864(storage + 0x30, -1);
        fn_115_48C4(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
