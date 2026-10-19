#pragma force_active on
void operator delete(void*);
extern "C" void* fn_113_391C(void*, short);
extern "C" void* fn_113_4188(void*, short);

extern "C" void* fn_113_38AC(void* object, short deleting) {
    if (object != 0) {
        fn_113_391C(static_cast<unsigned char*>(object) + 0x1F50, -1);
        fn_113_4188(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
