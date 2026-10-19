#pragma force_active on
void operator delete(void*);
extern "C" void* fn_121_16E9C(void*, short);
extern "C" void* fn_121_1715C(void*, short);

extern "C" void* fn_121_16E2C(void* object, short deleting) {
    if (object != 0) {
        fn_121_16E9C(static_cast<unsigned char*>(object) + 0x3110, -1);
        fn_121_1715C(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
