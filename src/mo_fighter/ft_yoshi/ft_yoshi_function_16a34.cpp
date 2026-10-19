#pragma force_active on
void operator delete(void*);
extern "C" void* fn_95_38A4(void*, short);
extern "C" void* fn_95_16AA4(void*, short);

extern "C" void* fn_95_16A34(void* object, short deleting) {
    if (object != 0) {
        fn_95_38A4(static_cast<unsigned char*>(object) + 0x18A4, -1);
        fn_95_16AA4(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
