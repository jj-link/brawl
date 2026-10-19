#pragma force_active on
void operator delete(void*);
extern "C" void* fn_94_15D34(void*, short);
extern "C" void fn_94_16228(void*, short);

extern "C" void* fn_94_161BC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_94_15D34(storage + 0x6D54, -1);
        fn_94_16228(storage + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
