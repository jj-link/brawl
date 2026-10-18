#pragma force_active on
struct Queue {
    virtual void unused08();
    virtual void** front(int);
    virtual void unused10();
    virtual void unused14();
    virtual int empty();
    virtual void unused1c();
    virtual void pop();
};

struct Input {
    virtual void unused08();
    virtual void unused0c();
    virtual int get(int);
};

struct Owner {
    virtual void unused08();
    virtual void unused0c();
    virtual void unused10();
    virtual int get();
    virtual void unused18();
    virtual void unused1c();
    virtual void unused20();
    virtual void unused24();
    virtual void unused28();
    virtual void unused2c();
    virtual void remove(void**);

    char pad[0x7c];
    Queue queue;
};

extern "C" int fn_113_24BEC(Owner*, void*, int, Input*);
extern "C" void fn_113_1B30C(void*, int, int);
extern "C" void fn_113_25530(Owner*);

extern "C" void fn_113_24558(Owner* self, Input* input) {
    int value = input->get(0);
    while (!self->queue.empty()) {
        void* item = *self->queue.front(0);
        int result = fn_113_24BEC(self, item, self->get(), input);
        fn_113_1B30C(item, value, result);
        void* local = item;
        self->remove(&local);
        self->queue.pop();
    }
    fn_113_25530(self);
}
