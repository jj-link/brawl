#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

class soTarget {
public:
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual s32 getCount(u32 flag);
    virtual void setValue(s32 value, u32 flag);
};

struct Stage2 {
    u8 pad[0x64];
    soTarget* target;
};

struct Stage1 {
    u8 pad[0xd8];
    Stage2* s2;
};

struct Root {
    u8 pad[0x60];
    Stage1* s1;
};

extern "C" s32 fn_27_299C94(void*, Root* root) {
    soTarget* t = root->s1->s2->target;
    s32 r = t->getCount(0x10000000);
    if (r > 0) {
        r = r - 1;
        t->setValue(r, 0x10000000);
    }
    return r;
}
