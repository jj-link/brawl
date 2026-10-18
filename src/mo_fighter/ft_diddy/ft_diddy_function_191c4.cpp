#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_191C4(void* object, short shouldDelete)
{
    if (object != 0 && shouldDelete > 0) {
        __dl__FPv(object);
    }
    return object;
}
