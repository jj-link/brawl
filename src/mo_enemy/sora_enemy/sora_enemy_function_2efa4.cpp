#pragma force_active on
extern "C" void* fn_27_CC7EC(void* member, short deleteFlag);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_2EFA4(void* object, short deleteFlag)
{
    if (object != 0) {
        fn_27_CC7EC(object, -1);
        if (deleteFlag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
