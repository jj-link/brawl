#pragma force_active on
extern "C" void fn_41_51BBC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_51C28(void* object, short flag) {
    if (object != 0) {
        fn_41_51BBC(static_cast<char*>(object) + 4, -1);
        if (flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
