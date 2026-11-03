#pragma force_active on

#define D(n) virtual void v##n();

struct Ground_base {
    char pad[0x3c];
};

class Ground : public Ground_base {
public:
    D(8) D(c)
    D(10) D(14) D(18) D(1c)
    D(20) D(24) D(28) D(2c)
    D(30) D(34) D(38) D(3c)
    D(40) D(44) D(48) D(4c)
    D(50) D(54) D(58) D(5c)
    D(60) D(64) D(68) D(6c)
    D(70) D(74) D(78) D(7c)
    D(80) D(84) D(88) D(8c)
    D(90) D(94) D(98)
    virtual void startup(void* archive, int a, int b);
    D(a0)
    virtual void setValue(void* value);
    D(a8) D(ac)
    D(b0) D(b4) D(b8) D(bc)
    D(c0) D(c4) D(c8) D(cc)
    D(d0) D(d4) D(d8) D(dc)
    D(e0) D(e4) D(e8) D(ec)
    D(f0) D(f4) D(f8) D(fc)
    D(100) D(104) D(108) D(10c)
    D(110) D(114) D(118) D(11c)
    D(120) D(124) D(128) D(12c)
    D(130) D(134) D(138) D(13c)
    D(140) D(144) D(148) D(14c)
    D(150) D(154) D(158) D(15c)
    D(160) D(164) D(168) D(16c)
    D(170) D(174) D(178) D(17c)
    D(180) D(184) D(188) D(18c)
    D(190) D(194) D(198) D(19c)
    D(1a0) D(1a4) D(1a8) D(1ac)
    D(1b0) D(1b4) D(1b8) D(1bc)
    D(1c0) D(1c4)
    virtual void fn_57_650(void* p);
    virtual void fn_57_658(void* p);
    D(1d0) D(1d4) D(1d8) D(1dc) D(1e0)
    virtual void slot119(void* p);
    virtual void slot120(void* p);
    virtual void slot121(int v);
};

struct Stage {
    char pad0[0x9c];
    void* value;
    char padA0[0x1c];
    int unkBC;
    char padC0[0xe0];
    void* archive;
    char pad1A4[0x38];
    char unk1DC[8];
    char unk1E4[4];
    char unk1E8[0x30];
    char unk218[1];
    void addGround(Ground* g);
};

extern "C" Ground* fn_57_5618(int, const char*, const char*);
extern char lbl_57_data_30[];
extern char lbl_57_data_40[];

extern "C" void fn_57_660(Stage* self, int kind) {
    Ground* ground;
    switch (kind) {
    case 2:
        ground = fn_57_5618(1, lbl_57_data_30, lbl_57_data_40);
        break;
    default:
        ground = 0;
        break;
    }
    if (ground) {
        self->addGround(ground);
        ground->startup(self->archive, 0, 0);
        ground->setValue(self->value);
        ground->slot119(&self->unk218);
        ground->slot120(&self->unk1E8);
        ground->slot121(self->unkBC);
        ground->fn_57_650(&self->unk1DC);
        ground->fn_57_658(&self->unk1E4);
    }
}
