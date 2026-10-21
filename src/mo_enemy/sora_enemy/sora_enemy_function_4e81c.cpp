#pragma force_active on
struct ValueObj {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual unsigned int getValue(unsigned int id);
};

struct Mod {
    unsigned char padding[0x64];
    ValueObj* value;
};

struct Accesser {
    unsigned char padding[0xD8];
    Mod* mod;
};

extern "C" {
void* fn_41_473DC(void* acc, unsigned int v);
void fn_41_47470(void* out, void* p, void* acc);
void fn_41_47544(unsigned char* out, void* p);
void fn_41_47A2C(void* p, void* acc, unsigned int flag);
void fn_41_47E80(void* buf, unsigned char flag, void* self, void* p, void* acc);

int fn_41_4E81C(void* self, Accesser* acc) {
    unsigned int val = acc->mod->value->getValue(0x10000007);
    void* p = fn_41_473DC(acc, val);
    unsigned int out[3];
    fn_41_47470(out, p, acc);
    unsigned char flag = 0;
    fn_41_47544(&flag, p);
    fn_41_47A2C(p, acc, 1);
    fn_41_47E80(out, flag, self, p, acc);
    return 0;
}
}
