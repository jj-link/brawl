#pragma force_active on
extern "C" int fn_41_43B8C(void* self, void* arg) {
    typedef unsigned int (*Callback)(void*);
    Callback callback = *(Callback*)self;
    if (callback(arg) == 1u) {
        ++*(unsigned int*)((char*)self + 4);
    } else {
        ++*(unsigned int*)((char*)self + 8);
    }
    return 1;
}
