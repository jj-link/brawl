#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A1CFC(void*, short);
extern "C" void* fn_118_5294(void*, short);

extern "C" void* fn_118_521C(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1CFC(static_cast<unsigned char*>(object) + 0x524, -1);
        if (object != 0) {
            fn_118_5294(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
