#pragma force_active on

typedef unsigned int u32;
typedef int s32;
typedef unsigned char u8;

struct Handle {
    u8 pad[4];
    void* id;
};

class Owner {
public:
    virtual void s0();
    virtual Handle* get(s32);
};

struct Self {
    u8 pad[0x28];
    Owner* owner;
};

struct A {
    u8 pad[0x10];
    u8 flags;
};

struct B {
    u8 pad[0x54];
    u8 flags;
};

struct C {
    u8 pad[0x2C];
    u8 flags;
};

struct QBits {
    u8 hi : 1;
    u8 rest : 7;
};

struct Local {
    u32 id;
    u8 pad1[4];
    A* a;
    B* b;
    C* c;
    u8 byte;
    QBits q;
};

extern "C" u32 fn_80111CB0(void*, void*);
extern "C" u32 fn_80134534(void*, u32);

extern "C" s32 fn_27_29D68(Self self, s32 arg1, s32 arg2) {
    Handle* h = self.owner->get(arg2);

    u32 mode;
    if ((arg1 & 1) != 0)
        mode = 0;
    else if ((arg1 & 8) != 0)
        mode = 3;
    else if ((arg1 & 2) != 0)
        mode = 1;
    else {
        mode = 0;
        if ((arg1 & 4) != 0)
            mode = 2;
    }

    u32 r = fn_80134534(h->id, mode);
    if (r != 0xFFFF) {
        Local l;
        s32 valid = 0;
        l.id = r;
        l.a = 0;
        l.b = 0;
        l.c = 0;
        l.byte = 0;
        l.q.hi = 0;

        s32 ok = fn_80111CB0(&l.id, &l.a) == 1;
        if (ok) {
            if (l.a != 0 && l.b != 0 && l.c != 0)
                valid = 1;

            s32 enabled;
            if (valid != 0 && ((l.b->flags >> 4) & 1) &&
                ((l.c->flags >> 7) & 1))
                enabled = 1;
            else
                enabled = 0;

            ok = enabled == 1;
        }

        if (ok)
            ok = ((l.a->flags >> 7) & 1) ^ 1;
        if (ok)
            return 1;
    }
    return 0;
}
