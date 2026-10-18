#pragma force_active on
extern "C" void fn_124_9BC4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_9C20(void* object, short shouldDelete) {
    if (object != 0) {
        fn_124_9BC4(static_cast<char*>(object) + 4, -1);
        if (shouldDelete > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
