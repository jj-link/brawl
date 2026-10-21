#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_27_234AF0(void*, void*, unsigned char);
extern "C" bool fn_27_234B2C(void*, void*);
extern "C" char lbl_27_data_4C410[];

struct Trigger {
    unsigned short id;
    unsigned char pad;
    unsigned char kind;
};

struct Data {
    unsigned int head;
    Trigger entries[5];
    unsigned char flag0;
    unsigned char flag1;
};

struct Object {
    unsigned int head;
    void* vtable;
    unsigned int field8;
    unsigned int fieldC;
    void* entries[5];
    unsigned int count;
    bool flag0;
    bool flag1;
};

struct Holder {
    char pad[0x18];
    Object* object;
    char pad1C[0x10];
    char context[1];
};

class Dispatch {
public:
    unsigned int head;
    virtual void v0();
    virtual void destroy(int);
};

inline void init(Object* obj, void* context, bool a, bool b) {
    fn_27_234AF0(obj, context, 0);
    obj->vtable = lbl_27_data_4C410;
    obj->count = 0;
    obj->flag0 = a;
    obj->flag1 = b;
    obj->entries[0] = 0;
    obj->entries[1] = 0;
    obj->entries[2] = 0;
    obj->entries[3] = 0;
    obj->entries[4] = 0;
}

extern "C" void fn_27_234700(Holder* self, Data* data) {
    Object* obj = (Object*)__nw__FUlQ25Heaps8HeapType(0x2C, 15);
    if (obj) {
        init(obj, self->context, data->flag0, data->flag1);
    }

    for (int i = 0; i < 5; ++i) {
        if (data->entries[i].id) {
            fn_27_234B2C(obj, &data->entries[i]);
        }
    }

    if (self->object) {
        if (self->object) {
            ((Dispatch*)self->object)->destroy(1);
        }
    }
    self->object = obj;
}
