#pragma force_active on
struct Obj {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void* slot4(unsigned int v);
};

struct Sub {
    unsigned char pad[0x64];
    Obj* obj;
};

struct Acc {
    unsigned char pad[0xD8];
    Sub* sub;
};

extern "C" {
void* fn_41_473DC(void* acc, void* v);
void fn_41_47470(void* out, void* p, void* acc);
void fn_41_47544(unsigned char* out, void* p);
void fn_41_47A2C(void* p, void* acc, unsigned int flag);
void fn_41_47D8C(void* out, unsigned int zero, void* self, void* p, void* acc);

int fn_41_5B574(void* self, Acc* acc) {
    unsigned int buf[2];
    unsigned char flag;
    void* v = acc->sub->obj->slot4(0x10000007);
    void* p = fn_41_473DC(acc, v);
    fn_41_47470(buf, p, acc);
    flag = 0;
    fn_41_47544(&flag, p);
    fn_41_47A2C(p, acc, 1);
    fn_41_47D8C(buf, flag, self, p, acc);
    return 0;
}
}
