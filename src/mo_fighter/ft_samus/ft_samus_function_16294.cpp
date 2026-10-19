#pragma force_active on
void operator delete(void*);
extern "C" void* fn_94_15D34(void*, short);
extern "C" void fn_94_16300(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_16294(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_94_15D34(storage + 0x419C, -1);
        fn_94_16300(storage + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
