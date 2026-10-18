#pragma force_active on
void operator delete(void*);

extern "C" void fn_121_D0CC(void*, short);

extern "C" void* fn_121_D12C(void* object, short deleting) {
    if (object != 0) {
        fn_121_D0CC(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
