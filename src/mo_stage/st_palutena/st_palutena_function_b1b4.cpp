#pragma force_active on
extern "C" {
void fn_67_2058(void* self);
void* __nwa__FUlQ25Heaps8HeapType(unsigned long, int);
void* __construct_new_array(void*, void*, void*, unsigned int, int);
void* memset(void* dst, int c, unsigned int n);
extern char lbl_67_data_2A20[];
extern void* fn_67_B444;
}

struct Item {
    char pad0[4];
    unsigned int f4;
    char pad8[0x78];
};

class Class_1898 {
public:
    virtual void fn_67_818C();
    virtual void fn_67_7654();
    virtual void fn_67_7664();
    virtual void fn_67_51C8();
    virtual void fn_67_4E88(int, int);
    Item* p4;
    int f8;
};

struct Object {
    char pad0[0x3c];
    void* f3c;
    char pad40[0x158 - 0x40];
    unsigned char f158;
    char pad159[3];
    void* f15c;
    void* f160;
    char pad164[4];
    void* f168;
    char pad16c[0x1d0 - 0x16c];
};

extern "C" Object* fn_67_B1B4(Object* self) {
    fn_67_2058(self);
    int zero = 0;
    self->f15c = (void*)zero;
    self->f3c = lbl_67_data_2A20;
    self->f168 = (void*)zero;
    self->f15c = (void*)__construct_new_array(__nwa__FUlQ25Heaps8HeapType(0x124, 0xF), &fn_67_B444, 0, 0xC, 0x17);
    self->f160 = __nwa__FUlQ25Heaps8HeapType(0x5c, 0xF);
    self->f168 = __nwa__FUlQ25Heaps8HeapType(0x5c, 0xF);
    memset(self->f15c, 0, 0x114);
    memset(self->f160, 0, 0x5c);
    memset(self->f168, 0, 0x5c);
    Class_1898* s = (Class_1898*)((char*)self + 0xd0);
    self->f158 = zero;
    if (s == 0) {
        return self;
    }
    s->f8 = 0x17;
    s->fn_67_4E88(0, 0xF);
    int idx = 0;
    for (int i = 0; i < 3; i++) {
        s->p4[idx].f4 = s->p4[idx].f4 | 1;
        s->p4[idx].f4 = s->p4[idx].f4 | 2;
        s->p4[idx + 1].f4 = s->p4[idx + 1].f4 | 1;
        s->p4[idx + 1].f4 = s->p4[idx + 1].f4 | 2;
        s->p4[idx + 2].f4 = s->p4[idx + 2].f4 | 1;
        s->p4[idx + 2].f4 = s->p4[idx + 2].f4 | 2;
        s->p4[idx + 3].f4 = s->p4[idx + 3].f4 | 1;
        s->p4[idx + 3].f4 = s->p4[idx + 3].f4 | 2;
        s->p4[idx + 4].f4 = s->p4[idx + 4].f4 | 1;
        s->p4[idx + 4].f4 = s->p4[idx + 4].f4 | 2;
        s->p4[idx + 5].f4 = s->p4[idx + 5].f4 | 1;
        s->p4[idx + 5].f4 = s->p4[idx + 5].f4 | 2;
        s->p4[idx + 6].f4 = s->p4[idx + 6].f4 | 1;
        s->p4[idx + 6].f4 = s->p4[idx + 6].f4 | 2;
        idx += 7;
    }
    s->p4[idx].f4 = s->p4[idx].f4 | 1;
    s->p4[idx].f4 = s->p4[idx].f4 | 2;
    (&s->p4[idx])[1].f4 = (&s->p4[idx])[1].f4 | 1;
    (&s->p4[idx])[1].f4 = (&s->p4[idx])[1].f4 | 2;
    return self;
}
