#pragma force_active on
void operator delete(void*);
extern "C" void* fn_97_3EC8(void*, short);
extern "C" void* fn_97_641C(void*, short);
extern "C" void* fn_27_CD934(void*, short);

extern "C" void* fn_97_63A4(void* object, short deleting) {
    if (object != 0) {
        short minusOne = -1;
        fn_97_3EC8(static_cast<unsigned char*>(object) + 0xAC, minusOne);
        fn_97_641C(static_cast<unsigned char*>(object) + 0x20, minusOne);
        fn_27_CD934(object, minusOne);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
