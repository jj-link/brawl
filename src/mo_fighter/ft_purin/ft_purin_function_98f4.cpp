#pragma force_active on
extern "C" void fn_124_9894(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_98F4(void* object, short count)
{
    if (object != 0) {
        fn_124_9894(static_cast<char*>(object) + 4, -1);
        if (count > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
