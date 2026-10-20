#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Param {
    int type;
    int unused;
    union {
        u16 seal;
        u32 value;
    } data;
    u8 flag;
};

struct Entry {
    u8 type;
    u8 pad[3];
    int id;
};

struct List {
    u16 values[100];
    u16 count;
};

struct Obj {
    u8 pad0[0x1A0];
    void* a;
    u8 pad1[0x530 - 0x1A4];
    void* b;
    void* result;
    void* c;
    u8 pad2[0x548 - 0x53C];
    int index;
    List list;
    u8 pad3[0x7B2 - 0x616];
    u16 ring[200];
    u8 pad4[2];
    int write;
    int read;
    int count;
    u8 pad5[0xD54 - 0x950];
    int timer;
};

struct Node {
    int unused;
    void* value;
};

struct Manager {
    u8 pad[0x14B8];
    Node* node;
};

extern "C" Manager* getInstance__9itManagerFv();
extern "C" void* fn_800C001C(void*, void*, void*, int, void*, int);
extern "C" void fn_800C1B04(void*, int, Param*);
extern "C" void fn_800C11A4(void*, Param*);
extern "C" void fn_800C1B20(void*, Param*);
extern "C" void fn_800C07D0(void*);
extern "C" const Entry lbl_15_rodata_1D0[];

inline void setSeal(void* result, u16 seal) {
    Param p;
    p.type = 0;
    p.data.seal = seal;

    int id = 0x75;
    if ((seal >= 0x5D && seal <= 0x7B) ||
        (seal >= 0x17F && seal <= 0x18A)) {
        id = 0x76;
    }

    fn_800C1B04(result, id, &p);
    fn_800C11A4(result, &p);
}

inline void setValue(void* result, u32 value) {
    Param p;
    p.type = 2;
    p.data.value = value;
    p.flag = 0;
    fn_800C1B04(result, 0x79, &p);
    fn_800C11A4(result, &p);
}

inline void setId(void* result, int id) {
    Param p;
    p.type = 4;
    p.data.value = id;
    fn_800C1B20(result, &p);
    fn_800C1B04(result, id, &p);
    fn_800C11A4(result, &p);
}

inline void push(Obj* self, u16 value) {
    if (self->count < 200) {
        self->ring[self->write] = value;
        if (++self->write >= 200) {
            self->write = 0;
        }
        ++self->count;
    }
}

extern "C" void fn_15_417C(Obj* self) {
    int index = self->index;
    void* value = 0;
    Node* node = getInstance__9itManagerFv()->node;
    if (node) {
        value = node->value;
    }

    self->result = fn_800C001C(self->b, self->c, self->a, 16, value, 0);

    switch (lbl_15_rodata_1D0[index].type) {
    case 0:
        setSeal(self->result, self->list.values[0]);
        break;
    case 1:
        setValue(self->result, *(u32*)&self->list);
        break;
    case 2:
        setId(self->result, lbl_15_rodata_1D0[index].id);
        break;
    }

    fn_800C07D0(self->result);

    if ((unsigned)(index - 2) <= 2) {
        List* list = &self->list;
        for (int i = 0; i < list->count; ++i) {
            push(self, list->values[i]);
        }
    }

    self->timer = 120;
}
