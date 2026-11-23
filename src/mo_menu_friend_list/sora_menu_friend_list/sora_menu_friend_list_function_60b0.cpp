#include <types.h>
#include <gf/gf_task.h>
#include <mu/mu_msg.h>
#include <nw4r/g3d/g3d_resmdl.h>
#include <stdio.h>
#include <string.h>
#pragma force_active on
#pragma opt_common_subs off
#pragma opt_propagation off

extern "C" {
void fn_800B7224(void*, unsigned long, const char*, void*);
int fn_80034924(void*, unsigned int, void*);
void fn_800B70D0(void*, const char*, void*);
int fn_800CCA9C(void*, int*, int*);
void fn_800CCEC4(void*, int);
void fn_800BF830(void*);
unsigned char fn_14_6538();
void fn_14_6544(...);

extern void* g_muWifiInterfaceTask;
extern const char lbl_14_data_0[];
extern const unsigned char lbl_14_rodata_21C[];
}

struct MenuObject {
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
    virtual void v13(void*);
};

inline int asInt(int value) { return value; }

struct Rgb {
    u8 a;
    u8 b;
    u8 c;
};

struct Friend {
    u8 a;
    u8 b;
    char pad[2];
    int value;
    char pad8[1];
    char name[0x67];
    int count;
    char pad74[0xc];
};

struct Model {
    char pad[8];
    nw4r::g3d::ResMdl mdl;
};

struct Self {
    char pad0[0x40];
    u8 f40;
    char pad41[0xa8 - 0x41];
    Model* model;
    char padac[0x190 - 0xac];
    struct F190 {
        char pad[0x10];
        void* f10;
    } *f190;
    char pad194[0x1e0 - 0x194];
    MenuObject* f1e0;
    char pad1e4[0x2b8 - 0x1e4];
    Friend friends[64];
    u8 sel[64];
    char pad22f8[0x24c4 - 0x22f8];
    int f24c4;
    char pad24c8[4];
    MuMsg* msg;
    char pad24d0[8];
    int f24d8;
    char pad24dc[8];
    int f24e4;
    char pad24e8[4];
    struct Task {
        char pad[0x104];
        int status;
    } *task;
    char pad24f0[0x2a1c - 0x24f0];
    MenuObject* f2a1c;
    int f2a20;
    char pad2a24[8];
    void* f2a2c;
    u8 f2a30;
    char pad2a31[3];
    int f2a34;
    u8 f2a38;
    u8 icons[128];
};

extern "C" int fn_14_60B0(Self* self) {
    const char* data = lbl_14_data_0;
    int off = self->sel[self->f24e4 + self->f24d8] << 7;
    int status = 0;
    char buf[32];
    char name[24];
    char avatar[40];

    u8 b = *(u8*)((char*)self + off + 0x2b9);
    if (b != 0xff) {
        sprintf(buf, data + 0x80, b < 0x80 ? self->icons[b] : 0);
        Model* model = self->model;
        nw4r::g3d::ResMat mat = model->mdl.GetResMat(data + 0x60);
        fn_800B7224(model, *(unsigned long*)((char*)mat.ptr() + 12), buf, 0);
    } else {
        void* ctx = self->f2a2c;
        const char* material = data + 0x60;
        u8 friendId = *(u8*)((char*)self + off + 0x2b8);
        Model* model = self->model;
        int result;
        if (ctx == 0) {
            result = 0;
        } else {
            result = fn_80034924(ctx, friendId, avatar);
        }
        if (result != 0) {
            fn_800B70D0(model, material, avatar);
        } else {
            const char* fallback = data + 0x6c;
            nw4r::g3d::ResMat mat = model->mdl.GetResMat(material);
            fn_800B7224(model, *(unsigned long*)((char*)mat.ptr() + 12),
                        fallback, 0);
        }
    }

    strcpy(name, (char*)self + off + 0x2c1);
    self->msg->printf(0x14, name);

    int x;
    int y;
    Rgb t4;
    Rgb t3;
    Rgb t2;
    Rgb t1;
    u8 sel2;
    void* wifi;
    int ca;
    int value = *(int*)((char*)self + off + 0x2bc);
    int k = (value << 2) - value;
    ca = lbl_14_rodata_21C[k];
    int cb = *(&lbl_14_rodata_21C[k] + 1);
    int cc = *(&lbl_14_rodata_21C[k] + 2);
    t1.a = ca;
    t1.b = cb;
    t1.c = cc;
    if (!self->f2a30 &&
        (value == 6 || value == 0x12 || value == 0x16 || value == 0x1c)) {
        t1.a = 0x11;
        t1.c = 6;
    }
    *(u16*)&t2 = *(u16*)&t1;
    t2.c = t1.c;
    self->msg->printIndex(0x15, t2.a, 0);

    t3.a = ca;
    t3.b = cb;
    t3.c = cc;
    if (!self->f2a30 &&
        (value == 6 || value == 0x12 || value == 0x16 || value == 0x1c)) {
        t3.a = 0x11;
        t3.c = 6;
    }
    *(u16*)&t4 = *(u16*)&t3;
    t4.c = t3.c;

    if (asInt(t4.b) > 0) {
        self->msg->printf(0x16, data + 0x3fc, *(int*)((char*)self + off + 0x328), t4.b);
    } else {
        self->msg->printf(0x16, data + 0x410);
    }

    if (!self->f40) {
        switch (fn_800CCA9C(g_muWifiInterfaceTask, &x, &y)) {
        case 1:
            status = 0;
            break;
        case 2:
            status = 1;
            break;
        case 6:
            status = 2;
            break;
        case 7:
            status = 3;
            break;
        default:
            status = 0;
            break;
        }
    }

    if (status == 0) {
        sel2 = self->sel[self->f24e4 + self->f24d8];
        wifi = g_muWifiInterfaceTask;
        u8 state = fn_14_6538();
        if (state == 0xff) {
            state = 4;
        }
        if (state == 4 && self->f2a20 != self->friends[sel2].value) {
            fn_14_6544(data + 0x4a0, self->f2a20, self->friends[sel2].value);
            if (!self->f40) {
                fn_800CCEC4(wifi, 0);
            }
            status = 5;
        }
    }

    if (status == 0 && self->task->status == 3) {
        if (!self->f40) {
            fn_800CCEC4(g_muWifiInterfaceTask, 0);
        }
        status = 4;
    }

    if ((unsigned int)(status - 2) <= 3) {
        fn_800BF830(self->task);
        ((gfTask*)self->task)->exit();
        self->task = 0;
        self->f1e0->v13(self->f190->f10);
        self->f2a1c->v13(self->f1e0);

        switch (status) {
        case 2:
            self->f2a34 = 0x1b;
            self->f2a38 = 1;
            break;
        case 4:
            self->f2a38 = 0;
            self->f2a34 = 0x19;
            break;
        case 3:
            self->f2a34 = 0x1c;
            self->f2a38 = 1;
            break;
        case 5:
            self->f2a38 = 0;
            self->f2a34 = 0x1a;
            break;
        }
        return 0xd;
    }

    if (status == 1) {
        return 0xc;
    }
    return self->f24c4;
}
