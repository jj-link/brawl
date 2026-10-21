#pragma force_active on

typedef unsigned char u8;

struct Arr {
    virtual void isNull() const;
    virtual int* at(int i);
    virtual int* atC(int i) const;
    virtual int size() const;
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void clear();
};

struct Self {
    char pad[0x30];
    Arr* a;
    Arr* b;
    void* unk38;
    Arr* c;
    char pad40[5];
    u8 flag80 : 1;
    u8 flag40 : 1;
    u8 flags : 6;
};

extern "C" void fn_27_A6BCC(int*);

extern "C" void fn_27_A38D8(Self* self) {
    int n = self->a->size();
    for (int i = 0; i < n; ++i)
        fn_27_A6BCC(self->a->at(i));

    self->a->clear();
    self->b->clear();

    n = self->c->size();
    for (int j = 0; j < n; ++j)
        *self->c->at(j) = -1;

    self->flag40 = 1;
    self->flag80 = 0;
}
