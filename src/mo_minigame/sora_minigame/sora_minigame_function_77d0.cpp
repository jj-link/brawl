#pragma force_active on
struct Elem { char pad[0x20]; unsigned char f20; char p2[3]; int f24; void* f28; };
extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern void* lbl_805A0EC8;
struct Vec;
extern "C" void fn_8027CE3C(Vec*, int);
struct Vec {
    Elem** data; int size;
    union {
        struct { unsigned int noFree:1; unsigned int b:1; unsigned int cap:30; } bf;
        unsigned int raw;
    };
    bool isOwned() const { return (raw & 0x80000000) == 0; }
    void push_back(Elem* e) {
        if (size == (int)bf.cap) fn_8027CE3C(this, 4);
        data[size++] = e;
    }
    void dealloc() { fn_8027EABC(lbl_805A0EC8, data, raw << 2, 0x15); }
    void clear() {
        if (isOwned()) dealloc();
        data = 0;
        size = 0;
        raw = (raw & 0x40000000) | 0x80000000;
    }
};
struct Obj { char pad[0x4c4]; Vec v1; char p2[0x4f4-0x4d0]; Vec v2; };
extern "C" void fn_802F0668(void*);
extern "C" void fn_20_77D0(Obj* o) {
    for (int i = o->v1.size - 1; i >= 0; i--) {
        if (o->v1.data[i]->f24 != 0) o->v1.data[i]->f20 = 1;
        fn_802F0668(o->v1.data[i]->f28);
        o->v2.push_back(o->v1.data[i]);
    }
    o->v1.clear();
}
