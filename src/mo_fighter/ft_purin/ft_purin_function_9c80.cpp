#pragma force_active on
extern "C" void fn_124_9C20(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_9C80(void* object, short flag)
{
    if (object != 0) {
        fn_124_9C20(static_cast<char*>(object) + 8, -1);
        if (flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
