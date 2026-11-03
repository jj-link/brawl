#pragma force_active on
extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern "C" int __cntlzw(unsigned int);
extern void* lbl_805A0EC8;

struct Vec8 {
    void* data;
    int size;
    unsigned int raw;
    bool isOwned() const { return (raw & 0x80000000) == 0; }
    void dealloc() { fn_8027EABC(lbl_805A0EC8, data, raw << 3, 0x15); }
    void clear() {
        if (isOwned())
            dealloc();
        data = 0;
        size = 0;
        raw = (raw & 0x40000000) | 0x80000000;
    }
};

struct Vec24 {
    void* data;
    int size;
    unsigned int raw;
    bool isOwned() const { return (raw & 0x80000000) == 0; }
    void dealloc() { fn_8027EABC(lbl_805A0EC8, data, (raw & 0x3FFFFFFF) * 0x24, 0x15); }
    void clear() {
        if (isOwned())
            dealloc();
        data = 0;
        size = 0;
        raw = (raw & 0x40000000) | 0x80000000;
    }
};

struct Vec4 {
    void* data;
    int size;
    unsigned int raw;
    bool isOwned() const { return (raw & 0x80000000) == 0; }
    void dealloc() { fn_8027EABC(lbl_805A0EC8, data, raw << 2, 0x15); }
    void clear() {
        if (isOwned())
            dealloc();
        data = 0;
        size = 0;
        raw = (raw & 0x40000000) | 0x80000000;
    }
};

struct VecMask {
    void* data;
    int size;
    unsigned int raw;
    bool isOwned() const { return (raw & 0x80000000) == 0; }
    void dealloc() { fn_8027EABC(lbl_805A0EC8, data, raw & 0x3FFFFFFF, 0x15); }
    void clear() {
        if (isOwned())
            dealloc();
        data = 0;
        size = 0;
        raw = (raw & 0x40000000) | 0x80000000;
    }
};

struct Obj {
    char pad0[0x40];
    Vec8 v1;
    char pad1[0x20];
    Vec24 v2;
    Vec4 v3;
    VecMask v4;
    char pad2[0x124];
    Vec4 v5;
    Vec4 v6;
    Vec4 v7;
    Vec4 v8;
};

extern "C" void fn_802E1B10(Obj* o) {
    if (o->v1.size == 0)
        o->v1.clear();
    if (o->v2.size == 0)
        o->v2.clear();
    if (o->v3.size == 0)
        o->v3.clear();
    if (o->v4.size == 0)
        o->v4.clear();

    {
        int found = 0;
        int off = 0;
        int n = o->v5.size;
        while (n > 0) {
            n--;
            if (*(int*)((char*)o->v5.data + off) != 0) {
                found = 1;
                break;
            }
            off += 4;
        }
        if (found == 0)
            o->v5.clear();
    }
    {
        int found = 0;
        int off = 0;
        int n = o->v6.size;
        while (n > 0) {
            n--;
            if (*(int*)((char*)o->v6.data + off) != 0) {
                found = 1;
                break;
            }
            off += 4;
        }
        if (found == 0)
            o->v6.clear();
    }
    {
        int found = 0;
        int off = 0;
        int n = o->v7.size;
        while (n > 0) {
            n--;
            if (*(int*)((char*)o->v7.data + off) != 0) {
                found = 1;
                break;
            }
            off += 4;
        }
        if (found == 0)
            o->v7.clear();
    }

    signed char c = (signed char)((unsigned int)__cntlzw((unsigned int)o->v8.size) >> 5);
    if (c != 0)
        o->v8.clear();
}