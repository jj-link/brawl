#pragma force_active on

typedef unsigned char u8;

extern "C" void fn_800B98DC(char*, u8);
extern "C" void fn_800B9804(void*, int);

struct Cfg {
    int f00;
    int f04;
    int count;
    int arr[5];
    u8 f20;
};

struct Obj {
    u8 pad0[0x1A8];
    int f1A8;
    u8 pad1[0x1B8 - 0x1AC];
    u8 b1B8[0x260 - 0x1B8];
    u8 b260[0x308 - 0x260];
    u8 pad2[0x17B8 - 0x308];
    int f17B8;
    int f17BC;
    u8 pad3[4];
    int f17C4;
    int f17C8;
    u8 pad4[0x17D8 - 0x17CC];
    int f17D8;
    int f17DC;
    int f17E0;
    int f17E4;
    u8 f17E8;
};

static inline u8 makeMask(const Cfg& cfg, int& i) {
    u8 mask = 0;
    for (; i < cfg.count; i++) {
        mask |= 1 << cfg.arr[i];
    }
    return mask;
}

extern "C" void fn_9_438(Obj* self, int arg1, const Cfg& cfg) {
    int i = 0;
    self->f1A8 = arg1;
    self->f17BC = cfg.count != 1;
    self->f17E0 = cfg.arr[2];
    self->f17D8 = cfg.arr[0];
    self->f17E4 = cfg.arr[3];
    self->f17DC = cfg.arr[1];
    fn_800B98DC((char*)self + 0x1B8, makeMask(cfg, i));
    fn_800B9804((char*)self + 0x260, (u8)cfg.arr[0]);
    if (cfg.count > 1) {
        fn_800B9804((char*)self + 0x308, (u8)cfg.arr[1]);
    }
    self->f17C8 = cfg.f04;
    self->f17B8 = cfg.f00;
    self->f17E8 = cfg.f20;
}
