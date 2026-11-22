#pragma force_active on
extern "C" int __cntlzw(unsigned int);
extern void* lbl_805A0EC8;

extern "C" {
void fn_8027CE3C(void* self, int n);
void fn_8027EABC(void* a, void* b, unsigned int c, int d);
void fn_802EA268(void* a, void* b);
}

struct PtrArray {
    void** data;
    int count;
    unsigned int cap;
    void* buf[16];
    bool isOwned() const { return (cap & 0x80000000) == 0; }
    void dealloc() { fn_8027EABC(lbl_805A0EC8, data, cap * 4, 0x15); }
};

class Node {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(PtrArray* out);
    unsigned short f4;
    short f6;
    char pad8[0xA8 - 8];
    unsigned char fA8;
};

struct Target {
    char pad0[0x22];
    unsigned short f22;
    char pad24[2];
    unsigned char hi26 : 2;
    unsigned char mode26 : 2;
    unsigned char lo26 : 4;
};

struct Owner {
    char pad0[0x40];
    PtrArray list;
};

struct Parent {
    char pad0[0x58];
    Target* f58;
    char pad5c[0x1D8 - 0x5C];
    Node** f1D8;
    int f1DC;
};

inline int accepts(PtrArray* out, Parent* arg1) {
    int add = 1;
    for (int j = 0; j < out->count; ++j) {
        int r5 = 0;
        Node* x = (Node*)out->data[j];
        signed char is7 = (unsigned int)__cntlzw(x->fA8 - 7) >> 5;
        if (is7 == 0 && (void*)x != (void*)arg1) r5 = 1;
        if (r5) {
            add = 0;
            break;
        }
    }
    return add;
}

extern "C" void fn_802F89F4(Owner* arg0, Parent* arg1, PtrArray* arg2) {
    PtrArray out;
    Node* e;
    int offset;
    Target* t;
    int i;
    t = arg1->f58;
    out.data = out.buf;
    out.count = 0;
    out.cap = 0x80000010;
    for (i = 0, offset = 0; i < arg1->f1DC; offset += 4, ++i) {
        e = *(Node**)((char*)arg1->f1D8 + offset);
        e->vf3(&out);
        if (accepts(&out, arg1)) {
            if (arg2->count == (int)(arg2->cap & 0x3FFFFFFF)) fn_8027CE3C(arg2, 4);
            arg2->data[arg2->count++] = e;
            if (e->f4 != 0) e->f6 = e->f6 + 1;
            fn_802EA268(t, e);
            t->mode26 = 1;
            if (t->f22 == 0xFFFF) {
                t->f22 = (unsigned short)arg0->list.count;
                if (arg0->list.count == (int)(arg0->list.cap & 0x3FFFFFFF)) fn_8027CE3C(&arg0->list, 4);
                arg0->list.data[arg0->list.count++] = t;
            }
        }
    }
    if (out.isOwned()) out.dealloc();
}
