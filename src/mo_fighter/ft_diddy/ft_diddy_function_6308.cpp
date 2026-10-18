#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A1FE4(void*, short);

extern "C" void* fn_115_6308(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short memberDeleteFlag = -1;
            fn_27_1A1FE4(object, memberDeleteFlag);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
