#pragma force_active on

typedef unsigned int u32;
typedef int s32;
typedef unsigned char u8;

extern "C" u32 fn_80111CB0(void*, void*);
extern "C" u32 fn_80134344(void*, u32);
extern "C" u32 fn_80134534(void*, u32);

struct Handle {
    u8 pad[4];
    void* id;
};

struct Ctx {
    u8 pad[0x2C];
    u8 flags;
};

class Owner {
public:
    virtual void s0();
    virtual Handle* get();
};

struct Self {
    u8 pad[0x28];
    Owner* owner;
};

struct QBits {
    u8 hi : 1;
    u8 rest : 7;
};

struct Local {
    u32 v;
    u8 pad1[4];
    u32 x;
    u32 y;
    Ctx* z;
    u8 w;
    QBits q;
};

extern "C" s32 fn_27_290A8(Self self) {
    Local l;
    Handle* h = self.owner->get();
    if (fn_80134344(h->id, 3) == 1) {
        u32 r = fn_80134534(h->id, 3);
        if (r != 0xFFFF) {
            l.v = r;
            l.x = 0;
            l.y = 0;
            l.z = 0;
            l.w = 0;
            l.q.hi = 0;
            if (fn_80111CB0(&l.v, &l.x) == 1) {
                u32 b = (l.z->flags >> 1) & 1;
                if (b == 1) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
