#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_6A3D8(void*, short);
extern "C" void* fn_27_199F7C(void*, short);

extern "C" void* fn_108_7278(void* object, short deleting) {
    short neg = -1;
    if (object != 0) {
        fn_27_6A3D8(static_cast<unsigned char*>(object) + 0x178, neg);
        fn_27_199F7C(object, neg);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
