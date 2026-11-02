#pragma force_active on
class Class_8042B6D0 {
public:
    virtual void fn_8004805C();
    virtual void fn_8004781C();
    virtual void fn_80046A28();
    virtual void fn_8004810C();
    virtual void fn_800480DC();
    virtual void fn_801AB1C4();
    virtual void fn_801B269C();
    virtual void fn_801B26E4();
    virtual void fn_801AAFDC();
    virtual void fn_801AAFE8();
    virtual void fn_801AB290();
    virtual void fn_801B2EEC();
    virtual void fn_801B3050();
    virtual int fn_801B3248(int arg);
};

struct Entry {
    Class_8042B6D0* obj;
    char pad[0x0a - 4];
    unsigned short cnt;
    char pad2[0x18 - 0x0c];
};

struct Owner {
    char pad[0x390];
    Entry table[16];
};

extern "C" int fn_8000D1B8(Owner* self, int idx, int arg) {
    int ret = 0;
    Class_8042B6D0* obj = self->table[idx].obj;
    if (obj != 0) {
        int r = obj->fn_801B3248(arg);
        ret = r;
        if (r != 0) {
            self->table[idx].cnt = self->table[idx].cnt - 1;
        }
    }
    return ret;
}
