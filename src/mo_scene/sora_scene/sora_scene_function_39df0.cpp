#pragma force_active on
#include <types.h>

struct GGData {
    char pad0[8];
    u8 f8 : 6;
    u8 f8b : 2;
    u8 f9 : 3;
    u8 f9b : 5;
    u8 fa0 : 1;
    u8 fa1 : 1;
    u8 fa2 : 1;
    u8 fa3 : 1;
    u8 fa4 : 4;
    u8 fb;
    u8 fc : 1;
    u8 fc1 : 7;
    char padd[0x13 - 0xd];
    u8 f13;
    char pad14[2];
    u8 f16;
    u8 pad17;
    u8 f18;
    u8 pad19;
    u16 f1a;
    char f1c[4];
    int f20;
    char pad24[0xc];
    int f30;
    int f34;
    int f38;
    int f3c;
    char pad40[0x1c];
    char f5c[4];
    u8 f60;
    u8 f61;
    u8 pad62;
    u8 f63;
    u8 f64;
    char pad65[3];
    int f68;
    int f6c;
    int f70;
    int f74;
    int f78;
    int f7c;
};

struct Self {
    char pad0[0x11];
    u8 f11;
    bool f12;
    u8 pad13;
    int f14;
    int f18;
    int f1c;
};

struct Info {
    char pad[0x20];
    u8 f20;
    u8 f21;
};

extern "C" {
extern GGData** g_GameGlobal;
extern int g_muWifiInterfaceTask;
void fn_8005033C(void*);
int fn_800CB0D8(int, int);
int fn_800CB824(int);
Info* fn_800CB834(int);
void fn_8010F960(u16, void*, void*, int);
void fn_1_32F8();
void fn_1_3D2D8();
void fn_1_3A1A8(Self*);
void fn_1_39F9C(Self*);
void fn_1_39DF0(Self* self);
}

void fn_1_39DF0(Self* self) {
    GGData* gg = g_GameGlobal[2];
    int task = g_muWifiInterfaceTask;
    fn_8005033C(gg);
    self->f14 = 0;
    self->f18 = 0;
    self->f1c = 0;
    for (int i = 0; i < 4; i++) {
        if (fn_800CB0D8(task, i) != 3) {
            self->f18++;
        }
    }
    self->f11 = 0;
    if (self->f12 = fn_800CB824(task) == 0) {
        fn_1_3A1A8(self);
    } else {
        fn_1_39F9C(self);
    }
    gg->f8 = 0x12;
    gg->f1a = 0x34;
    gg->f13 = self->f12 != 0;
    gg->f9 = 1;
    gg->f20 = 600;
    gg->fc = 0;
    gg->f18 = 0;
    gg->f63 = self->f11;
    gg->f64 = self->f12;
    gg->f68 = self->f14;
    gg->f6c = self->f1c;
    gg->fa3 = 1;
    gg->f70 = 0;
    gg->f74 = 0;
    gg->f78 = 0;
    gg->f7c = 0;
    gg->f34 = 0;
    gg->f30 = 0;
    gg->f38 = 0;
    gg->f3c = 0;
    gg->f16 = 0;
    Info* info = fn_800CB834(task);
    gg->f60 = info->f20;
    gg->f61 = info->f21;
    fn_8010F960(gg->f1a, gg->f1c, gg->f5c, 0);
    fn_1_32F8();
    fn_1_3D2D8();
}
