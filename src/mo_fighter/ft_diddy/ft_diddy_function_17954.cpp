#pragma force_active on
void operator delete(void*);
extern "C" void* fn_115_178F4(void*, short);
extern "C" void* fn_115_177D4(void*, short);

extern "C" void* fn_115_17954(void* object, short deleting) {
    if (object != 0) {
        fn_115_178F4(static_cast<unsigned char*>(object) + 0x44, -1);
        fn_115_177D4(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
