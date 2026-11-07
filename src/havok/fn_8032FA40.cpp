#pragma force_active on
extern "C" {
extern char lbl_80488ED8[];
extern void* lbl_805A0EC8;
void fn_8027EABC(void*, void*, unsigned int, int);
}
class Object_vptr_0 {
public:
    virtual void slot0(int);
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
};
class Class_80488EE0 {
public:
    virtual void fn_8032FA40(int);
    virtual void fn_80080A64();
    virtual void fn_8032FCB4();
    virtual void fn_80330928();
    virtual void fn_8033259C();
    virtual void fn_803315A4();
};
struct Alloc {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void f(void*, int, int);
};
extern "C" Alloc* lbl_805A0EB8;
struct Elem {
    virtual void d(int);
    unsigned short u4;
    short u6;
};
struct Arr8 {
    void* data;
    int size;
    int cap;
    int getCapacity() const { return cap & 0x3FFFFFFF; }
    ~Arr8() {
        if (!(cap & 0x80000000)) {
            int c = getCapacity();
            fn_8027EABC(lbl_805A0EC8, data, c * 8, 0x15);
        }
    }
};
struct Arr4 {
    void* data;
    int size;
    int cap;
    int getCapacity() const { return cap & 0x3FFFFFFF; }
    ~Arr4() {
        if (!(cap & 0x80000000)) {
            int c = getCapacity();
            fn_8027EABC(lbl_805A0EC8, data, c * 4, 0x15);
        }
    }
};
struct Obj {
    void* vt;
    unsigned short u4;
    char pad6[2];
    Elem* elem;
    char padc[8];
    Arr4 arr;
    char pad20[0x44];
    Arr8* ptr;
    Object_vptr_0* other;
};
extern "C" Obj* fn_8032FA40(Obj* self, int flag) {
    if (self) {
        self->vt = lbl_80488ED8;
        if (self->other) self->other->slot0(1);
        Arr8* p = self->ptr;
        if (p) {
            if (!(p->cap & 0x80000000)) {
                int c = p->getCapacity();
                fn_8027EABC(lbl_805A0EC8, p->data, c * 8, 0x15);
            }
            lbl_805A0EB8->f(p, 12, 0x15);
        }
        Elem* e = self->elem;
        if (e->u4 != 0) {
            if (--e->u6 == 0 && e) e->d(1);
        }
        if (&self->arr) self->arr.~Arr4();
        if (flag > 0) lbl_805A0EB8->f(self, self->u4, 6);
    }
    return self;
}