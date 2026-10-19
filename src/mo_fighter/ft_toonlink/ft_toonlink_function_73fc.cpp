#pragma force_active on
void operator delete(void*);
extern "C" void* fn_121_739C(void*, short);
extern "C" void* fn_121_6ACC(void*, short);

extern "C" void* fn_121_73FC(void* object, short deleting) {
    if (object != 0) {
        fn_121_739C(static_cast<unsigned char*>(object) + 0x16D8, -1);
        fn_121_6ACC(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
