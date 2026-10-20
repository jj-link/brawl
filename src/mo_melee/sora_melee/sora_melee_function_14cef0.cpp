#pragma force_active on
struct ftManager;
struct ftOwner;

extern "C" ftOwner* getOwner__9ftManagerFi(ftManager*, int);
extern ftManager* g_ftManager;

struct ftSub {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4(int arg);
};

struct ftMid {
    unsigned char pad[0x64];
    ftSub* sub;
};

struct ftSrc {
    unsigned char pad[0xd8];
    ftMid* mid;
};

struct ftSelf {
    unsigned char pad[0x178];
    ftOwner* owner;
};

extern "C" {
void fn_27_14CEF0(ftSelf* self, ftSrc* src) {
    ftManager* mgr = g_ftManager;
    ftSub* sub = src->mid->sub;
    int id = sub->v4(0x10000000);
    self->owner = getOwner__9ftManagerFi(mgr, id);
}
}
