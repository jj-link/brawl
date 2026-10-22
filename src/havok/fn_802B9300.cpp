#pragma force_active on
struct Target {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void process(unsigned short);
};

struct Object {
    virtual void done(int);
    virtual void unused1();
    int unk4;
    Target* target;
    unsigned short* array;
    int count;
};

extern "C" void fn_802B9300(Object* self) {
    int count = self->count;
    for (int i = 0; i < count; i++) {
        unsigned short val = self->array[i];
        if (val != 0xffff) {
            self->target->process(val);
        }
    }
    if (self) {
        self->done(1);
    }
}
