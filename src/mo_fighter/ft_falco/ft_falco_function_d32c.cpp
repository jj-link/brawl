#pragma force_active on
void operator delete(void*);
extern "C" void fn_108_D2CC(void*, short);

extern "C" void* fn_108_D32C(void* object, short deleting) {
    if (object != 0) {
        fn_108_D2CC(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
