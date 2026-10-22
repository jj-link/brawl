#pragma force_active on
struct Obj {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12();
    virtual void f(void*);
};
struct E { char pad[0x10]; void* f; };
extern "C" void fn_800E4CA4(char* self) {
    char* p = self;
    Obj* sub = *(Obj**)(self + 0xF4);
    int i;
    for (i = 0; i < 3; i++, p += 0xC) {
        if (*(int*)(p + 0x26C) == 0) break;
        sub->f((*(E**)(p + 0x270))->f);
        *(int*)(p + 0x26C) = 0;
    }
    *(unsigned char*)(self + 0x28C) = 0;
}
