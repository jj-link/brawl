#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_61_96CC(void* object, int flag)
{
    if (object != 0) {
        if (flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
