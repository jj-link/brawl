#pragma force_active on

extern "C" void fn_27_5AF08(void* object);

struct Entry {
    int a;
    void* b;
};

struct Table {
    int unk0;
    int unk4;
    Entry* entries;
    int count;
};

class Obj {
public:
    virtual void fn_27_5B4D0();                  // offset 0x8
    virtual void fn_27_5BC5C();                  // offset 0xc
    virtual void fn_27_5B57C();                  // offset 0x10
    virtual void fn_27_5B490(int, void*, int);   // offset 0x14
    virtual void fn_27_5B5AC();                  // offset 0x18

    char pad[0x1C];
    Table* table;                                // offset 0x20
};

extern "C" void fn_27_5B4D0(Obj* self) {
    int off = 0;
    int count = self->table->count;
    int i = 0;
    for (; i < count; i++) {
        Entry* e = (Entry*)((char*)self->table->entries + off);
        self->fn_27_5B490(e->a, e->b, 0);
        off += 8;
    }
    self->fn_27_5B5AC();
    fn_27_5AF08(self);
}
