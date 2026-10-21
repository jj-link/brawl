#pragma force_active on
struct Mod {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void* getValue(unsigned int kind);
};

struct Holder {
    unsigned char padding[0x64];
    Mod* mod;
};

struct Accesser {
    unsigned char padding[0xD8];
    Holder* holder;
};

extern "C" {
void* fn_41_473DC(void* acc, unsigned int v);
void fn_41_47470(void* out, void* p, void* acc);
void fn_41_47544(unsigned char* out, void* p);
void fn_41_47A2C(void* p, void* acc, unsigned int flag);
void fn_41_47D8C(void* out, unsigned char flag, void* self, void* p, void* acc);

int fn_41_AD60(void* self, void* acc) {
    unsigned char flag;
    unsigned int buf[4];
    Accesser* accesser = (Accesser*)acc;
    Mod* mod = accesser->holder->mod;
    void* p = fn_41_473DC(acc, (unsigned int)mod->getValue(0x10000007));
    fn_41_47470(buf, p, acc);
    flag = 0;
    fn_41_47544(&flag, p);
    fn_41_47A2C(p, acc, 1);
    fn_41_47D8C(buf, flag, self, p, acc);
    return 0;
}
}
