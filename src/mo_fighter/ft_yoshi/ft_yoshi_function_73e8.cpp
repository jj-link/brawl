#pragma force_active on
extern "C" {
void fn_27_66114(void*, short);
void operator delete(void*);

void* fn_95_73E8(void* obj, short flags) {
    if (obj != 0) {
        fn_27_66114(obj, static_cast<short>(-1));
        if (flags > 0) {
            operator delete(obj);
        }
    }
    return obj;
}
}
