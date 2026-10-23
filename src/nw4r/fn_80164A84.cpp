#pragma force_active on

struct Entry {
    char pad[0x18];
    unsigned short count;
    char rest[2];
};

struct Ctx {
    char pad0[0xC];
    int state;
    int flag;
    char pad2[8];
    virtual void f2();
    virtual void f3(int, void*);
    char pad1[0x20];
    int idx;
};

extern "C" int fn_80164A84(void* arg0, Ctx* arg1) {
    if (arg1->state != 1) {
        return 0;
    }

    Entry* base = (Entry*)(*(char**)((char*)arg0 + 0x5018));
    Entry* e = (Entry*)((char*)base + arg1->idx * 0x1C);
    unsigned short t = e->count;
    e->count = t - 1;
    arg1->f3(t, e);
    arg1->state = 2;

    if (arg1->flag == 0) {
        arg1->f2();
    }

    return 1;
}
