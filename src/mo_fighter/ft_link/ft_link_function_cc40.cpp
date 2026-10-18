#pragma force_active on
struct State {
    void* vtable;
    int first;
    int second;
};

typedef unsigned int (*Callback)(void*);

extern "C" int fn_93_CC40(State* self, void* arg) {
    Callback callback = *(Callback*)self;
    unsigned int result = callback((char*)arg + 0x88);
    if (result == 1) {
        self->first++;
    } else {
        self->second++;
    }
    return 1;
}
