#pragma force_active on
extern "C" void printf__5MuMsgFUlPCce(void*, unsigned long, const char*, ...);
extern char lbl_8059E3D4[4];

struct V {
    virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4();
    virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9();
    virtual void u10(); virtual void u11(); virtual void u12();
    virtual void call(void*);
};

struct S {
    char p[0x50];
    struct { char q[0x10]; void* d; } *a;
    struct { char q[0x10]; void* d; } *b;
    char pad[4];
    V* v;
    char r[0x08];
    int x;
    char s[0x20];
    void* m;
};

extern "C" float fn_800F238C(S*, int);

extern "C" void fn_800F3FA0(S* self) {
    fn_800F238C(self, self->x == 0 ? 6 : 1);
    int b = 2;
    if (self->x == 0) b = 1;
    printf__5MuMsgFUlPCce(self->m, b, lbl_8059E3D4);
    V* v = self->v;
    v->call(self->a->d);
    v->call(self->b->d);
}
