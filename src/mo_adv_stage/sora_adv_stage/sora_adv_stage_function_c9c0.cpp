#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

struct Vec2 {
    float x;
    float y;
};

struct Element {
    u32 f0;
    u32 f4;
    u32 f8;
    u8 pad0[0x28 - 0x0c];
    float fx;
    float fy;
    u8 pad1[0x34 - 0x30];
    u16 id;
    u8 pad2[0x37 - 0x36];
    u8 flag;
};

struct Sub {
    u32 a;
    u32 count;
};

struct Container {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual Element* getElement(u32 idx);
    u32 pad4;
    Sub* sub;
};

extern void* g_stTriggerMng;

extern "C" {
void* fn_80158BE0();
u32 fn_8015911C(void*, u16, u8);
void fn_27_234280(void*, Element*, Vec2*);
void* createTrigger__12stTriggerMngFQ27Gimmick8AreaKindP13stTriggerData(void*, int, void*);
Container* searchContainer__20stDataMultiContainerFUlUl(void*, u32, u32);

void fn_40_C9C0(void* unused, u32 a, void* b) {
    Container* c;
    for (u32 idx = 0; (c = searchContainer__20stDataMultiContainerFUlUl(b, a, idx++)) != 0;) {
        for (u32 i = 0; i < c->sub->count; i++) {
            Element* e = c->getElement(i);
            if (fn_8015911C(fn_80158BE0(), e->id, e->flag) != 1) {
                void* m = createTrigger__12stTriggerMngFQ27Gimmick8AreaKindP13stTriggerData(g_stTriggerMng, 6, &e->id);
                e->f4 = 0x19;
                e->f8 = 0x20000;
                float fy = e->fy;
                float fx = e->fx;
                Vec2 src;
                src.y = fy;
                src.x = fx;
                Vec2 tmp = src;
                fn_27_234280(m, e, &tmp);
            }
        }
    }
}
}
