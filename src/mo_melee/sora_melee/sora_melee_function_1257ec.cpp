#include <types.h>
#pragma force_active on

class ObserverBase {
public:
    virtual void addObserver(short, s8);
    virtual void n1();
    virtual void n2();
    virtual void n3();
    virtual void n4();
    virtual void n5();
    virtual void n6();
    virtual void n7();
    virtual void n8();
};

class BssFactory {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void* v3(int);
};

class EvSysView {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int v6(s16);
};

class MgrView {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual u32 v4(u32);
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void* v8(s16);
};

class UnitView {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual int v7();
};

struct Observer {
    void* vtable;
    short a;
    short b;
    short c;
};

struct Self {
    char pad0[0x64];
    Observer obs[14];
    char pad19C[0x2C];
    unsigned char d1C4_hi : 3;
    unsigned char d1C4_lo : 5;
    unsigned char d1C5;
    void* p1C8;
    short d1cc;
    short d1ce;
    void* p1d0;
    int d1d4;
};

extern "C" {
extern char lbl_27_bss_466C[];
extern void* g_ftManager;
extern char __vt__21soStatusEventObserver[];
extern char lbl_27_data_59A0[];
extern char lbl_27_data_7284[];
extern char lbl_27_data_5A18[];
extern char lbl_27_data_148A0[];
extern char lbl_27_data_29DE8[];
extern char lbl_27_data_29D58[];
extern char lbl_27_data_7270[];
extern char lbl_27_data_2A000[];
extern char lbl_27_data_29BC8[];
extern char lbl_27_data_29B58[];
extern char lbl_27_data_2A278[];
extern char lbl_27_data_2A0E8[];
extern char lbl_27_data_29AD8[];
extern char lbl_27_data_29600[];
extern char lbl_27_data_261F0[];
extern char lbl_27_data_261B0[];
extern char lbl_27_data_26440[];
extern char __RTTI__11soEventUnit[];

void fn_27_3860(void*, void*, int, int, int, int, int);
int fn_27_10B500(void*, int);
void* __dynamic_cast(void*, long, const void*, const void*, long);
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
}

extern "C" Self* fn_27_1257EC(Self* self, int arg1, int arg2, int arg3, int arg4) {
    int a17;
    int a10;
    int r0;
    int result;

    a17 = arg4;
    a10 = 0;
    r0 = 4;

    fn_27_3860(self, ((BssFactory*)lbl_27_bss_466C)->v3(arg2), 10, 6, 3, 0, a17);

    {
        Observer& o = self->obs[0];
        o.a = -1; o.b = r0; o.c = -1; o.vtable = __vt__21soStatusEventObserver;
        ((ObserverBase*)&o)->addObserver(-1, -1);
        Observer& o1 = self->obs[1];
        o1.a = -1; o1.b = 8; o1.c = -1; o1.vtable = lbl_27_data_59A0;
        ((ObserverBase*)&o1)->addObserver(-1, -1);
        Observer& o2 = self->obs[2];
        o2.a = -1; o2.b = 1; o2.c = -1; o2.vtable = lbl_27_data_7284;
        ((ObserverBase*)&o2)->addObserver(-1, -1);
        Observer& o3 = self->obs[3];
        o3.a = -1; o3.b = a10; o3.c = -1; o3.vtable = lbl_27_data_5A18;
        ((ObserverBase*)&o3)->addObserver(-1, -1);
        Observer& o4 = self->obs[4];
        o4.a = -1; o4.b = 14; o4.c = -1; o4.vtable = lbl_27_data_148A0;
        ((ObserverBase*)&o4)->addObserver(-1, -1);
        Observer& o5 = self->obs[5];
        o5.a = -1; o5.b = 15; o5.c = -1; o5.vtable = lbl_27_data_29DE8;
        ((ObserverBase*)&o5)->addObserver(-1, -1);
        Observer& o6 = self->obs[6];
        o6.a = -1; o6.b = 16; o6.c = -1; o6.vtable = lbl_27_data_29D58;
        ((ObserverBase*)&o6)->addObserver(-1, -1);
        Observer& o7 = self->obs[7];
        o7.a = -1; o7.b = 17; o7.c = -1; o7.vtable = lbl_27_data_7270;
        ((ObserverBase*)&o7)->addObserver(-1, -1);
        Observer& o8 = self->obs[8];
        o8.a = -1; o8.b = 13; o8.c = -1; o8.vtable = lbl_27_data_2A000;
        ((ObserverBase*)&o8)->addObserver(-1, -1);
        Observer& o9 = self->obs[9];
        o9.a = -1; o9.b = 12; o9.c = -1; o9.vtable = lbl_27_data_29BC8;
        ((ObserverBase*)&o9)->addObserver(-1, -1);
        Observer& o10 = self->obs[10];
        o10.a = -1; o10.b = 10; o10.c = -1; o10.vtable = lbl_27_data_29B58;
        ((ObserverBase*)&o10)->addObserver(-1, -1);
        Observer& o11 = self->obs[11];
        o11.a = -1; o11.b = 6; o11.c = -1; o11.vtable = lbl_27_data_2A278;
        ((ObserverBase*)&o11)->addObserver(-1, -1);
        r0 = fn_27_10B500(g_ftManager, arg1);
        Observer& o12 = self->obs[12];
        o12.a = -1; o12.b = 2; o12.c = -1; o12.vtable = lbl_27_data_2A0E8;
        ((ObserverBase*)&o12)->addObserver(r0, -1);
        Observer& o13 = self->obs[13];
        o13.a = -1; o13.b = 18; o13.c = -1; o13.vtable = lbl_27_data_29AD8;
        ((ObserverBase*)&o13)->addObserver(-1, -1);
    }

    *(void**)((char*)self + 0x3C) = lbl_27_data_29600;
    *(void**)((char*)self + 0x40) = lbl_27_data_29600 + 0x64;
    *(void**)((char*)self + 0x48) = lbl_27_data_29600 + 0x70;
    *(void**)((char*)self + 0x54) = lbl_27_data_29600 + 0x84;
    self->obs[0].vtable = lbl_27_data_29600 + 0xdc;
    self->obs[1].vtable = lbl_27_data_29600 + 0xec;
    self->obs[2].vtable = lbl_27_data_29600 + 0xfc;
    self->obs[3].vtable = lbl_27_data_29600 + 0x110;
    self->obs[4].vtable = lbl_27_data_29600 + 0x128;
    self->obs[5].vtable = lbl_27_data_29600 + 0x140;
    self->obs[6].vtable = lbl_27_data_29600 + 0x158;
    self->obs[7].vtable = lbl_27_data_29600 + 0x16c;
    self->obs[8].vtable = lbl_27_data_29600 + 0x180;
    self->obs[9].vtable = lbl_27_data_29600 + 0x190;
    self->obs[10].vtable = lbl_27_data_29600 + 0x1c4;
    self->obs[11].vtable = lbl_27_data_29600 + 0x1d4;
    self->obs[12].vtable = lbl_27_data_29600 + 0x1e8;
    self->obs[13].vtable = lbl_27_data_29600 + 0x254;

    *(int*)((char*)self + 0x10C) = arg1;
    *(int*)((char*)self + 0x110) = arg2;
    self->d1C4_lo = 0;
    self->d1C5 = ((u32)self->d1C5 | 0x80) & 0xFFFFFFBF;
    self->p1C8 = lbl_27_data_261F0;
    self->d1cc = -1;
    self->d1ce = a10;
    self->p1d0 = (void*)a10;

    if (self->d1cc > 0 && self->d1cc > -1) {
        if (((EvSysView*)getInstance__13soEventSystemFv())->v6(self->d1cc) != 0) {
            MgrView* m1 = (MgrView*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->d1cc);
            if (m1->v4(self->d1ce) == 0) {
                self->p1d0 = (void*)a10;
            } else {
                MgrView* m2;
                short kind = self->d1ce;
                m2 = (MgrView*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->d1cc);
                if (m2->v4(kind) == 0) {
                    result = 0;
                } else {
                    UnitView* u = (UnitView*)__dynamic_cast(m2->v8(kind), 0, lbl_27_data_26440, __RTTI__11soEventUnit, 0);
                    if (u == 0) {
                        result = 0;
                    } else {
                        result = u->v7();
                    }
                }
                self->p1d0 = (void*)result;
            }
        }
    }

    self->d1d4 = arg1;
    self->p1C8 = lbl_27_data_261B0;
    return self;
}
