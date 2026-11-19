#pragma force_active on
struct Cnt { virtual void s0(); virtual void s1(); virtual void s2(); virtual int s3(); };
struct Idx { virtual void s0(); virtual int s1(int); };
struct Get { virtual void s0(); virtual void s1(); virtual int s2(); };
struct Mod { char pad[0xc0]; Get* m; };
struct In { char pad[0xd8]; Mod* d; };
struct Obj { char pad[0x24]; char sub[4]; void* h; char pad2[0x54 - 0x2c]; In* p; };
extern "C" void fn_27_2E9A0(int, int, int, int, int, void*);
extern "C" void fn_27_25928(Obj* self, int** a, int b, int c) {
    int n = ((Cnt*)self->h)->s3();
    char* sub;
    Get* m;
    int x;
    int off;
    int i;
    i = 0;
    off = 0;
    for (; i < n; i++) {
        sub = (char*)self;
        if (self) sub += 0x24;
        m = self->p->d->m;
        x = ((Idx*)self->h)->s1(i);
        fn_27_2E9A0(x, b, *(int*)((char*)*a + off), m->s2(), c, sub);
        off += 4;
    }
}