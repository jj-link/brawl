#pragma force_active on

struct Data {
    char pad[0x238];
    void* arr238[6];
    void* arr250[5];
};

struct Ptr650 {
    char pad[0x38];
    void* field_38;
    void* field_3C;
};

struct Obj {
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
    virtual void v12();
    virtual void call13(void*);
};

struct Self {
    char pad[0x64C];
    Data* data64c;
    Ptr650* ptr650;
    Obj* obj654;
    char pad658[0x1C];
    void* ptr674;
    void* ptr678;
};

extern "C" {

void fn_800B8EDC(void*, void*);
void free__13gfHeapManagerFPv(void*);

void fn_2_27B40(Self* self) {
    self->obj654->call13(self->ptr650->field_38);
    self->obj654->call13(self->ptr650->field_3C);

    int i = 0;
    int off = 0;
    while (i < 6) {
        fn_800B8EDC(self->ptr674, *(void**)((char*)self->data64c + 0x238 + off));
        i++;
        off += 4;
    }

    int j = 0;
    int off2 = 0;
    while (j < 5) {
        fn_800B8EDC(self->ptr674, *(void**)((char*)self->data64c + 0x250 + off2));
        j++;
        off2 += 4;
    }

    free__13gfHeapManagerFPv(self->ptr678);
}

}
