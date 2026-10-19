#pragma force_active on
struct FtC {
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void* v7(int a, unsigned int b) = 0;
};

struct FtB {
    char pad[0x64];
    FtC* c;
};

struct FtA {
    char pad[0xd8];
    FtB* b;
};

struct FtOwner {
    char pad[0x60];
    FtA* a;
};

extern "C" {
void* fn_122_D2D8(FtOwner* owner) {
    return owner->a->b->c->v7(0, 0x10000040);
}
}
