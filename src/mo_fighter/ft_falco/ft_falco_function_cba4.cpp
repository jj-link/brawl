#pragma force_active on
void operator delete(void*);
extern "C" void* fn_108_CB44(void*, short);
extern "C" void* fn_108_CA24(void*, short);

extern "C" void* fn_108_CBA4(void* object, short deleting) {
    if (object != 0) {
        fn_108_CB44(static_cast<unsigned char*>(object) + 0x60, -1);
        fn_108_CA24(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
