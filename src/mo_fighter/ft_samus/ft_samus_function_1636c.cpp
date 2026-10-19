#pragma force_active on
void operator delete(void*);
extern "C" void* fn_94_15D34(void*, short);
extern "C" void* fn_94_163D8(void*, short);

extern "C" void* fn_94_1636C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_94_15D34(storage + 0x15E4, -1);
        fn_94_163D8(storage + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
