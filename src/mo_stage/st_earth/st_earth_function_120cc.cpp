#pragma force_active on
extern "C" {
void fn_66_2C60(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_66_120CC(void* object, int size)
{
    if (object != 0) {
        fn_66_2C60(object, 0);
        if (size > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
