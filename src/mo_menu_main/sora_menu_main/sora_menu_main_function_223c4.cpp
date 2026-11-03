#pragma force_active on

extern "C" {

void fn_800B8EDC(void*, void*);
void fn_800B8A0C(void*, int);
void free__13gfHeapManagerFPv(void*);

}

class Obj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void process(int);
    virtual void call(void*);
    char pad[0xE0];
    int next;
};

struct Data {
    char pad[0x1F8];
    void* arr1F8[6];
    void* ptr210;
};

struct Ptr650 {
    char pad[0x2C];
    Obj* item2C;
};

struct Self {
    char pad0[0x64C];
    Data* data64c;
    Ptr650* ptr650;
    Obj* obj654;
    char pad658[0x1C];
    void* ptr674;
    char pad678[4];
    void* ptr67C;
};

extern "C" void fn_2_223C4(Self* self) {
    int n;
    Obj* it = self->ptr650->item2C;
    while (n = it->next) {
        if (n == 0) continue;
        it->process(n - 1);
    }
    self->obj654->call(self->ptr650->item2C);
    if (self->ptr674 != 0) {
        free__13gfHeapManagerFPv(self->ptr674);
    }
    int off;
    int i = 0;
    off = 0;
    while (i < 6) {
        fn_800B8EDC(self->ptr67C, *(void**)((char*)self->data64c + 0x1F8 + off));
        i++;
        off += 4;
    }
    fn_800B8EDC(self->ptr67C, self->data64c->ptr210);
    fn_800B8A0C(self->ptr67C, 1);
}
