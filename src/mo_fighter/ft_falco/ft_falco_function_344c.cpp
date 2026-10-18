#pragma force_active on
void operator delete(void*);

extern "C" void* fn_108_34AC(void*, short);

extern "C" void* fn_108_344C(void* object, short deleting) {
    if (object != 0) {
        fn_108_34AC(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
