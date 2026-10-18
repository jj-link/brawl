#pragma force_active on
void operator delete(void*);
extern "C" void* fn_118_BB68(void*, short);

extern "C" void* fn_118_BBC8(void* object, short deleting) {
    if (object != 0) {
        fn_118_BB68(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
