#pragma force_active on

struct Target {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual int read(void*, int);
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void reset(int, int);
};

struct Context {
    unsigned char reserved[0x10];
    Target* target;
    void* data;
    int size;
    void (*callback)(int, int, void*);
    void* user;
};

extern "C" void fn_801C2E84(int*, void*);
extern "C" int fn_801C2EF0(int*);

extern "C" void fn_801C484C(Context* self) {
    self->target->reset(0, 0);
    int result = self->target->read(self->data, self->size);
    self->target = 0;

    if (result == -3) {
        if (self->callback) {
            self->callback(0, 0, self->user);
        }
    } else if (result != self->size) {
        if (self->callback) {
            self->callback(0, 0, self->user);
        }
    } else {
        int value[2];
        fn_801C2E84(value, self->data);
        int output = fn_801C2EF0(value);
        if (self->callback) {
            self->callback(1, output, self->user);
        }
    }
}
