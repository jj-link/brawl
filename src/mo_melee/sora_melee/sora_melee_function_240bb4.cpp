#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {
extern void* g_GameGlobal;
extern void* g_IfAdvMngr;
extern char lbl_27_data_4D958[];
void* __nw__FUlQ25Heaps8HeapType(u32, int);
void* __ct__9gfArchiveFv(void*);
void __dt__9gfArchiveFv(void*, short);
void __dt__14gfFileIOHandleFv(void*, short);
void __dl__FPv(void*);
void fn_1_3C68(void*, int, void*, void*, u32);
int fn_1_3E50(void*);
void fn_1_406C(void*);
void fn_27_23B44C(void*, u32*, u32*, u32*, u32*);
void fn_80106A5C(void*, void*);
void fn_80106A64(void*, u32, u32, u32, u32);
void fn_80106D10(void*);
int fn_80106E40(void*);
}

struct LoaderBits {
    u8 pad[0x1C];
    bool b0 : 1;
    bool b1 : 1;
    bool b2 : 1;
};

struct TaskBase { u8 pad[0x3c]; };
struct Task : TaskBase {
    virtual void processDefault();
    virtual void fn_27_240BB4();
    virtual void processAnim();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void processFixPosition();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void processFixCamera();
    virtual void processEffect();
    virtual void processGameProc();
    virtual void processEnd();
    virtual void renderPre();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void renderDebug();
    virtual void init();
    virtual void fn_27_240B5C();
    virtual void fn_27_240E6C();
    virtual void fn_27_240F28();
    virtual int fn_27_23ABA0();
    u32 pad40;
    u8 state;
    u8 pad45;
    u8 flag46;
    u8 flag47;
    u8 pad48[0x18];
    void* ptr60;
    void* archive64;
    void* loader68;
};

extern "C" void fn_27_240BB4(Task* self) {
    if (self->flag46 != 0) {
        u8* r30 = (u8*)g_IfAdvMngr;
        u8* gg = *(u8**)((u8*)g_GameGlobal + 0x30);
        if (gg[0x604] != 2) {
            *(u32*)(r30 + 0x50) = *(u32*)(gg + 0x4910);
        }
        switch ((int)self->state) {
        case 0:
            if (self->flag47 != 1) {
                Task* o = (Task*)self->ptr60;
                if (o == 0 || o->fn_27_23ABA0() != 0) {
                    self->state = 1;
                }
            }
            break;
        case 1:
            if (r30 != 0) {
                void* a = __nw__FUlQ25Heaps8HeapType(0x80, 9);
                if (a != 0) {
                    a = __ct__9gfArchiveFv(a);
                }
                self->archive64 = a;
                void* b = __nw__FUlQ25Heaps8HeapType(0x20, 9);
                if (b) {
                    u8* q = (u8*)b;
                    LoaderBits* L = (LoaderBits*)b;
                    *(u32*)(q + 0x00) = 0;
                    *(u32*)(q + 0x04) = 0;
                    u32* t658 = (u32*)(q + 0x08);
                    *t658 = 0;
                    *(u32*)(q + 0x0C) = 0;
                    *(u32*)(q + 0x10) = 0;
                    L->b0 = 0;
                    *(u32*)(q + 0x18) = 0;
                    *(u32*)(q + 0x14) = 0xFF;
                    L->b1 = 0;
                    L->b2 = 0;
                }
                self->loader68 = b;
                fn_1_3C68(b, 9, lbl_27_data_4D958, self->archive64, 0);
                fn_80106A5C(r30, self->archive64);
            }
            self->state = 2;
            break;
        case 2:
            if (r30 != 0) {
                if (fn_1_3E50(self->loader68) != 0 && fn_80106E40(r30) != 0) {
                    if (self->ptr60 != 0) {
                        u32 sp14, sp10, spC, sp8;
                        fn_27_23B44C(self->ptr60, &sp14, &sp10, &spC, &sp8);
                        fn_80106A64(g_IfAdvMngr, sp14, sp10, spC, sp8);
                    } else {
                        fn_80106A64(g_IfAdvMngr, 0, 0, 0, 0);
                    }
                    self->state = 3;
                    break;
                }
            } else {
                self->state = 3;
            }
            break;
        case 3:
            if (self->flag47 == 1) {
                self->state = 5;
            }
            break;
        case 5:
            self->fn_27_240F28();
            if (r30 != 0) {
                fn_80106D10(r30);
                if (self->archive64 != 0) {
                    __dt__9gfArchiveFv(self->archive64, 1);
                    self->archive64 = 0;
                }
                void* b = self->loader68;
                if (b != 0) {
                    if (b != 0) {
                        fn_1_406C(b);
                        __dt__14gfFileIOHandleFv(b, -1);
                        __dl__FPv(b);
                    }
                    self->loader68 = 0;
                }
            }
            if (self->flag47 == 1) {
                self->state = 6;
            } else {
                self->state = 0;
            }
            break;
        }
    }
}
