#pragma force_active on
extern "C" void fn_27_1A09B4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_22FC(void* object, int count) {
    if (object != 0) {
        fn_27_1A09B4(object, -1);
        if (static_cast<short>(count) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
