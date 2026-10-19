#pragma force_active on
void operator delete(void*);
extern "C" void* fn_118_B720(void*, short);

extern "C" void* fn_118_B7E0(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            fn_118_B720(static_cast<unsigned char*>(object) + 0x4, -1);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
