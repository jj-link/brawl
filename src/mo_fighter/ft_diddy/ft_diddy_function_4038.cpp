#pragma force_active on
void operator delete(void*);
extern "C" void* fn_115_40A8(void*, short);
extern "C" void* fn_115_4548(void*, short);

extern "C" void* fn_115_4038(void* object, short deleting) {
    if (object != 0) {
        fn_115_40A8(static_cast<unsigned char*>(object) + 0x1FA8, -1);
        fn_115_4548(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
