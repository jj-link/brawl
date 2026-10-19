#pragma force_active on
void operator delete(void*);
extern "C" void* fn_92_11BFC(void*, short);
extern "C" void* fn_92_11EBC(void*, short);

extern "C" void* fn_92_11B8C(void* object, short deleting) {
    if (object != 0) {
        fn_92_11BFC(static_cast<unsigned char*>(object) + 0x1960, -1);
        fn_92_11EBC(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
