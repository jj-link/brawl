#pragma force_active on
extern "C" void* fn_41_2F078(void* object, short count);

extern "C" void* fn_41_2F0D8(void* object, short flag) {
    if (object != 0) {
        fn_41_2F078(object, 0);
        if (flag > 0) {
            operator delete(object);
        }
    }
    return object;
}
