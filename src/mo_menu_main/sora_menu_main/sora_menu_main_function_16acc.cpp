#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Class_728_base { char pad[0x3c]; };
struct Class_728 : Class_728_base {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void fn_2_36914();
    virtual void fn_2_36908();
    virtual void fn_2_361C4(int, int);
};

struct Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11(void*, void*);
    char pad[0xe0];
    void* e4;
};

struct Owner {
    char pad0[0x42];
    u16 sel;
    char pad1[0x64c - 0x44];
    void* list;
    char pad2[0x4];
    void* arg;
    Class_728* sub;
    char pad3[0x8];
    int zero;
};

extern "C" {
extern void* g_GameGlobal;
void* getGlobalRecordMenuDatap__10GameGlobalFv(void*);
void fn_800B330C(void*, void*, int);
extern u8 lbl_2_data_1F78[];
}

extern "C" void fn_2_16ACC(Owner* self, Obj* arg) {
    self->arg = arg;
    self->zero = 0;
    u8* rec = (u8*)getGlobalRecordMenuDatap__10GameGlobalFv(g_GameGlobal);
    u32 flag = (rec[0x28] >> 7) & 1;
    self->sel = flag;
    self->sub->fn_2_361C4(0x14, flag + 0x3c);
    for (u32 i = 0; i < 2; i++) {
        u32 off = i * 4;
        arg->v11(arg->e4, *(void**)((u8*)*(void**)((u8*)self->list + off + 0x9c) + 0x10));
    }
    for (int i = 0; i < 2; i++) {
        if (i == self->sel) {
            fn_800B330C(*(void**)((u8*)self->list + i * 4 + 0x9c), lbl_2_data_1F78, 1);
        } else {
            fn_800B330C(*(void**)((u8*)self->list + i * 4 + 0x9c), lbl_2_data_1F78 + 0x14, 1);
        }
    }
}
