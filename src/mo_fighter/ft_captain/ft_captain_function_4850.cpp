#pragma force_active on
extern "C" void fn_100_4914(void*, short);

extern "C" void* fn_100_4850(char* object, short flag) {
    if (object) {
        if (object) {
            fn_100_4914(object + 4, -1);
        }
        if (flag > 0) {
            operator delete(object);
        }
    }
    return object;
}
