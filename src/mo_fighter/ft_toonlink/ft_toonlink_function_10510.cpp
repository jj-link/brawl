#pragma force_active on

typedef int s32;

struct Out {
    s32 a, b, c;
};

struct Local {
    s32 f00, f04, mode, id;
    Out out;
};

class LinkModule {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16(s32, void*, s32);
};

struct Accesser {
    char pad[0xD8];
    void** unk;
};

extern "C" void fn_121_100DC(Local*);

extern "C" Out fn_121_10510(Accesser* accesser) {
    Local local;
    LinkModule* link = (LinkModule*)accesser->unk[0x54 / 4];
    fn_121_100DC(&local);
    local.mode = 7;
    local.id = 0x12D;
    link->v16(0, &local, 0);
    return local.out;
}
