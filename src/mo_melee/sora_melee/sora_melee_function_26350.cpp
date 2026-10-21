#pragma force_active on

struct Entity {
    char pad[0x80];
    int field80;
};

struct Entry {
    char pad[4];
    Entity* entity;
};

struct Array {
    virtual void v0();
    virtual Entry* get(int);
    virtual void v2();
    virtual int size();
};

struct Owner {
    char pad[0x28];
    Array* array;
    void* field2C;
    void* field30;
    void* field34;
};

extern "C" void fn_27_2EAE8(Entry*);
extern "C" void fn_801108D0(void*, int);
extern "C" void __dla__FPv(void*);
extern "C" void __dl__FPv(void*);

extern "C" void fn_27_26350(Owner* self) {
    int count = self->array->size();
    for (int i = 0; i < count; ++i) {
        fn_27_2EAE8(self->array->get(i));
    }

    if (self->field34) {
        __dla__FPv(self->field34);
        self->field34 = 0;
    }

    if (self->field30) {
        fn_801108D0(self->field30, 1);
        self->field30 = 0;
        if (self->array->size() > 0) {
            self->array->get(0)->entity->field80 = 0;
        }
    }

    if (self->field2C) {
        __dl__FPv(self->field2C);
        self->field2C = 0;
    }
}
