#pragma force_active on
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned char u8;

extern "C" int fn_27_23AC10(void*);
extern "C" void* fn_27_1D53E4(u32*, u32, u32);
extern "C" void* getOwner__9ftManagerFi(void*, int);
extern "C" void fn_27_23E45C(void*);
extern "C" void* g_ftManager;
extern "C" void* g_GameGlobal;

class SoraObj {
    char pad[0x3C];

public:
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
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void callback();

    struct Sub {
        u8 pad[8];
        u8 flags;
    };
    Sub* sub;      // 0x40
    char pad2[4];  // 0x44
    u32 idx;       // 0x48
    u32 id;        // 0x4C
};

extern "C" void fn_27_23E394(SoraObj* self) {
    if ((u32)((self->sub->flags >> 2) & 0x3F) == 6) {
        if (fn_27_23AC10(self) != 0) {
            if (self->idx < 2) {
                void* owner = getOwner__9ftManagerFi(g_ftManager, self->id);
                void* base = *(void**)owner;
                s32 val = (s32)fn_27_1D53E4((u32*)((u8*)base + 0x9e8), 0x1f, 0);
                u32 tbl = *(u32*)((u8*)g_GameGlobal + 0x30);
                *(s32*)((u8*)tbl + self->idx * 4 + 0x4918) += val;
            }
        }
    }
    if (fn_27_23AC10(self) != 0) {
        self->callback();
    }
    fn_27_23E45C(self);
}
