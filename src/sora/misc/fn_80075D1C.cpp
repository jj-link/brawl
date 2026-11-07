#pragma force_active on
class Snd {
public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void stop14(); virtual void stop18(int);
    virtual void v5(); virtual void v6();
    virtual void f24(int);
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void f38(int, float);
};
extern "C" void fn_801CA7E8(void*);
extern "C" void fn_801BD4A4(Snd*, int, float);
extern unsigned int lbl_805A01D4;
struct Id {
    unsigned int v;
    bool valid() const { return v != 0xFFFFFFFF; }
};
struct Entry {
    Snd* handle;
    int a;
    int b;
    Id id;
    unsigned int type;
    int c;
    int d;
    unsigned short e;
    short f;
    bool isActive() {
        bool r = false;
        if (id.valid() && e != 0) r = true;
        return r;
    }
    bool isUsed() {
        if (isActive()) return true;
        return handle != 0;
    }
    void reset() {
        if (handle) handle->stop18(0);
        fn_801CA7E8(&handle);
        a = -1;
        b = -1;
        id.v = 0xFFFFFFFF;
        type = 0;
        c = 0x40;
        d = 0;
        e = 0;
        a = lbl_805A01D4 + f;
        lbl_805A01D4 = (lbl_805A01D4 + 0x100) & 0x7FFFFF00;
    }
};
struct Mgr {
    char pad[0x2d4];
    Entry entries[32];
    char pad2[0x6ed - 0x2d4 - 0x400];
    unsigned char flag;
    char pad3[0x70c - 0x6ee];
    float f70c;
    float f710;
    char pad4[4];
    float f718;
};

extern "C" void fn_80075D1C(Mgr* m, unsigned int idx, int arg, int force) {
    if (idx == 0xFFFFFFFF) return;
    unsigned int id = m->entries[idx].id.v;
    if (id != 0xFFFFFFFF && m->entries[idx].type == 0xb) force = 1;
    if (force) {
        for (unsigned int i = (idx + 1) & 0x1f; idx != i; i = (i + 1) & 0x1f) {
            if (m->entries[i].id.v == id && m->entries[i].isUsed() && i != 0xFFFFFFFF) {
                m->entries[i].reset();
            }
        }
    }
    if (m->flag) {
        if (m->entries[idx].handle) m->entries[idx].handle->stop14();
        if (m->entries[idx].handle) m->entries[idx].handle->f24(arg);
        Snd* h = m->entries[idx].handle;
        float s = m->f70c * m->f718;
        if (h) h->f38(0, s);
        Snd* h2 = m->entries[idx].handle;
        float t = m->f710;
        if (h2) fn_801BD4A4(h2, 0, t);
    }
}
