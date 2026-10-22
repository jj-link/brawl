#pragma force_active on
struct Sub { char d[1]; };
extern "C" {
extern char lbl_80489098[];
extern struct Alloc* lbl_805A0EB8;
extern void* lbl_805A0EC8;
int fn_8027DD18(Sub*);
void* fn_8027DD78(Sub*, int);
int fn_8027DD98(Sub*, int);
unsigned fn_8027DDE0(Sub*, int);
void fn_8027E188(Sub*);
void fn_8027DC80(Sub*, int);
void fn_8027EABC(void*, void*, int, int);
}

struct Elem {
    virtual void d(int);
    unsigned short u4;
    short u6;
};

struct Arr {
    void* data;
    int size;
    int cap;
    int getCapacity() const { return cap & 0x3FFFFFFF; }
    ~Arr() {
        if ((cap & 0x80000000) == 0) {
            int c = getCapacity();
            fn_8027EABC(lbl_805A0EC8, data, c * 4, 0x15);
        }
    }
};

struct Obj {
    void* vt;
    unsigned short u4;
    char pad[2];
    Arr arr;
    Sub sub;
};

struct Alloc {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void f(void*, int, int);
};

extern "C" Obj* fn_803341E4(Obj* self, int flag) {
    if (self) {
        self->vt = lbl_80489098;
        int i = fn_8027DD18(&self->sub);
        while ((signed char)(fn_8027DDE0(&self->sub, i) >> 24) != 0) {
            Elem* e = (Elem*)fn_8027DD78(&self->sub, i);
            if (e->u4 != 0) {
                if (--e->u6 == 0 && e) {
                    e->d(1);
                }
            }
            i = fn_8027DD98(&self->sub, i);
        }
        fn_8027E188(&self->sub);
        if (&self->sub) fn_8027DC80(&self->sub, -1);
        self->arr.~Arr();
        if (flag > 0) {
            lbl_805A0EB8->f(self, self->u4, 0x16);
        }
    }
    return self;
}
