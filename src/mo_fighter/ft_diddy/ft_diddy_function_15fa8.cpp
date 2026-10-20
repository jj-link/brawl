#pragma force_active on
void operator delete(void*);
extern "C" void* fn_115_173D0(void*, short);
extern "C" void* fn_115_4864(void*, short);
extern "C" void* fn_115_48C4(void*, short);

extern "C" void* fn_115_15FA8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_115_173D0(storage + 0xE0, -1);
        fn_115_4864(storage + 0x30, -1);
        fn_115_48C4(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
