#pragma force_active on
struct Listener {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void notify();
};

struct Entry {
    unsigned int first;
    unsigned int second;
};

struct State {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int test();

    Listener* listener;
    Entry* current;
    int count;
};

extern "C" void fn_27_1D240(State* self) {
    if (self->test() == 0) {
        if (self->count > 0) {
            if (--self->count <= 0) {
                self->current = 0;
            } else {
                ++self->current;
            }
        } else if (self->listener) {
            self->listener->notify();
        }
    }
}
