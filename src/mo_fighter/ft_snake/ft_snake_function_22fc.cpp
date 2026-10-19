#pragma force_active on
extern "C" void fn_27_1A09B4(void*, short);

extern "C" void* fn_122_22FC(void* object, short flag) {
    if (object != 0) {
        fn_27_1A09B4(object, static_cast<short>(-1));
        if (flag > 0) {
            operator delete(object);
        }
    }
    return object;
}
