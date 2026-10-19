#pragma force_active on
void operator delete(void*);
extern "C" void* fn_92_146CC(void*, short);
extern "C" void* fn_92_1498C(void*, short);

extern "C" void* fn_92_1465C(void* object, short deleting) {
    if (object != 0) {
        fn_92_146CC(static_cast<unsigned char*>(object) + 0x1894, -1);
        fn_92_1498C(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
