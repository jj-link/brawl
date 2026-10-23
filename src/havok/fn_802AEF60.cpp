#pragma force_active on
#pragma use_lmw_stmw on

typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned char u8;

struct Sub {
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f13(s16* data, s32 count, void* out);
};

struct Entry {
    Sub* obj;
    s32 unk4;
};

struct Owner {
    u8 pad[0x10];
    Entry* table;
};

struct Out {
    s32 a;
    s32 b;
    s32 c;
    s32 unkC;
};

extern "C" void fn_802AEF60(Owner* arg0, u16* arg1, s32 arg2, Out* arg3) {
    s16 sp8;
    s32 i;
    s32 idx;

    i = 0;
    while (i < arg2) {
        idx = *arg1 >> 8;
        sp8 = (u8)*arg1;
        arg0->table[idx].obj->f13(&sp8, 1, arg3);
        arg1++;
        i++;
        s32 value = arg3->unkC;
        value += idx << 8;
        arg3->unkC = value;
        arg3++;
    }
}
