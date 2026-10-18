#pragma force_active on
void operator delete(void*);

extern "C" void fn_121_17568(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_121_17508(void* object, short deleting) {
    if (object != 0) {
        fn_121_17568(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
