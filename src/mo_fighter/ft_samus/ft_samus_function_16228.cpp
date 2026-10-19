#pragma force_active on
void operator delete(void*);
extern "C" void* fn_94_15D34(void*, short);
extern "C" void* fn_94_16294(void*, short);

extern "C" void* fn_94_16228(void* object, short deleting) {
    if (object != 0) {
        fn_94_15D34(static_cast<unsigned char*>(object) + 0x5778, -1);
        fn_94_16294(static_cast<unsigned char*>(object) + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
