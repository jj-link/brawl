#include <gf/gf_task.h>
#include <gf/gf_homemenu.h>
#include <gf/gf_shutdown_manager.h>
#include <gf/gf_file_io_handle.h>
#pragma force_active on

struct Scene {
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void attach(void*, void*);
    virtual void v38();
    virtual void detach(void*);
    char pad[0xe0];
    void* fieldE4;
};

struct Parent {
    char pad[0x48];
    Scene* scene;
};

struct Obj {
    char pad[0xc];
    void* model;
};

struct Message : gfTask {
    char pad40[0xc0];
    u8 unk100;
    char pad101[3];
    s32 status;
    char pad108[0x18];
    u8 unk120;
};

struct Res {
    char pad0[8];
    gfFileIOHandle handle;
    char pad1[0x94];
    s32 a0;
    s32 a4;
    char pad2[0x48];
    s32 f0;
};

struct MenuBoot {
    char pad0[0x40];
    Res* res;
    s32 unk44;
    u8 unk48;
    char pad49[3];
    void* unk4C;
    s32 unk50;
    s32 unk54;
    u8 unk58;
    char pad59[3];
    s32 unk5C;
    char arr60[8];
    Message* msg;
    Parent* parent;
    Obj* obj;
    s32 unk74;
    s32 state;
    s32 count;
};

extern "C" {
void OSReport(const char* fmt, ...);
void fn_800BF830(void* p);
void fn_800BF828(void* p, int a);
void fn_800BF97C(void* p, int a, int b);
void fn_800BFA04(void* p, int a, int b);
void fn_800B753C(void* p, float f);
void fn_800309F8(void* p, int a, int b);
void fn_80030954(void* p, int a, int b);
void fn_80030F64(void* p, int a);
void fn_8004EAE0(void** a, u8 b);
void fn_8004EB20(void* a, void* b);
u32 fn_800305B0(int a);
void free__13gfHeapManagerFPv(void* p);
Message* fn_800BEEB8(int, int, int, void*, Scene*, int, int, int, int, int, int, int);
extern char lbl_22_data_0[];
extern float lbl_22_rodata_0;
extern void* g_GameGlobal;
}

extern "C" void fn_22_E4(MenuBoot* self) {
    char* base = lbl_22_data_0;
    s32 shared_id;
    switch (self->state) {
    case 0:
        break;
    case 1:
        self->state = 2;
        break;
    case 2: {
        u8 f = (u8)(self->unk48 | 0x1f);
        self->unk48 = f;
        fn_8004EAE0((void**)g_GameGlobal, f);
        fn_80030954(self->res, 0x2b, 8);
        self->state = 3;
        break;
    }
    case 3: {
        Res* res = self->res;
        if (res->f0 == 0) {
            if (res->a0 == 0) {
                self->unk44 = res->a4;
                self->state = 4;
            } else {
                OSReport(base + 0xc);
                self->state = 0x3c;
            }
        }
        break;
    }
    case 4:
        switch (self->unk44) {
        case 0:
            self->state = 0x37;
            break;
        case 1:
            self->unk50 = 0;
            self->unk4C = (void*)((char*)self->res + 0xa8);
            self->state = 0x19;
            break;
        case 2:
            self->state = 5;
            break;
        }
        break;
    case 5: {
        s32 id = self->unk5C;
        if (self->msg) { fn_800BF830(self->msg); self->msg->exit(); self->msg = 0; }
        Message* m = fn_800BEEB8(1, id, 0, self->arr60, self->parent->scene, 0x14, 0, 0x2a, 0x2b, 0, 0, 0xf0);
        self->msg = m;
        m->unk120 = 1;
        fn_800BF97C(self->msg, self->unk5C, 0xe);
        fn_800BFA04(self->msg, self->unk5C, 0xf);
        self->state = 6;
        break;
    }
    case 6:
        if (self->msg->status == 3) {
            self->unk74 = self->msg->unk100;
            self->state = 7;
        }
        break;
    case 7:
        if (self->msg) { fn_800BF830(self->msg); self->msg->exit(); self->msg = 0; }
        if (self->unk74 == 1) self->state = 8;
        if (self->unk74 == 0) self->state = 0x16;
        break;
    case 8: {
        s32 id = self->unk5C;
        if (self->msg) { fn_800BF830(self->msg); self->msg->exit(); self->msg = 0; }
        Message* m = fn_800BEEB8(3, id, 1, self->arr60, self->parent->scene, 0x14, -1, 0x2a, 0x2b, 0, 0, 0xf0);
        self->msg = m;
        m->unk120 = 1;
        fn_800309F8(self->res, 0x2b, 8);
        Scene* sc = self->parent->scene;
        sc->attach(sc->fieldE4, self->obj->model);
        fn_800B753C(self->obj, lbl_22_rodata_0);
        self->state = 9;
        break;
    }
    case 9:
        if (g_gfHomeMenu->setBan(1, 0) == 1U) self->state = 0xa;
        break;
    case 0xa:
        if (self->res->f0 == 0) {
            fn_800BF828(self->msg, 2);
            Scene* sc = self->parent->scene;
            sc->detach(self->obj->model);
            self->state = 0xb;
        }
        break;
    case 0xb:
        if (self->msg->status == 3) self->state = 0xc;
        break;
    case 0xc:
        g_gfHomeMenu->setBan(0, 0);
        if (self->msg) { fn_800BF830(self->msg); self->msg->exit(); self->msg = 0; }
        switch (self->res->a0) {
        case 0: self->state = 0xd; break;
        case 1: self->state = 0x10; break;
        case 2: self->state = 0x13; break;
        case 3:
            OSReport(base + 0x28);
            self->state = 0x3c;
            break;
        }
        break;
    case 0xd: {
        s32 id = self->unk5C;
        if (self->msg) { fn_800BF830(self->msg); self->msg->exit(); self->msg = 0; }
        Message* m = fn_800BEEB8(0, id, 2, self->arr60, self->parent->scene, 0x14, 0, 0x2a, 0x2b, 0, 0, 0xf0);
        self->msg = m;
        m->unk120 = 1;
        self->state = 0xe;
        break;
    }
    case 0xe:
        if (self->msg->status == 3) self->state = 0xf;
        break;
    case 0xf:
        if (self->msg) { fn_800BF830(self->msg); self->msg->exit(); self->msg = 0; }
        self->state = 2;
        break;
    case 0x10: {
        s32 id = self->unk5C;
        if (self->msg) { fn_800BF830(self->msg); self->msg->exit(); self->msg = 0; }
        Message* m = fn_800BEEB8(0, id, 3, self->arr60, self->parent->scene, 0x14, 0, 0x2a, 0x2b, 0, 0, 0xf0);
        self->msg = m;
        m->unk120 = 1;
        self->state = 0x11;
        break;
    }
    case 0x11:
        if (self->msg->status == 3) self->state = 0x12;
        break;
    case 0x12:
        if (self->msg) { fn_800BF830(self->msg); self->msg->exit(); self->msg = 0; }
        self->state = 0x16;
        break;
    case 0x13: {
        s32 id = self->unk5C;
        if (self->msg) { fn_800BF830(self->msg); self->msg->exit(); self->msg = 0; }
        Message* m = fn_800BEEB8(0, id, 4, self->arr60, self->parent->scene, 0x14, 0, 0x2a, 0x2b, 0, 0, 0xf0);
        self->msg = m;
        m->unk120 = 1;
        self->state = 0x14;
        break;
    }
    case 0x14:
        if (self->msg->status == 3) self->state = 0x15;
        break;
    case 0x15:
        if (self->msg) { fn_800BF830(self->msg); self->msg->exit(); self->msg = 0; }
        self->state = 0x16;
        break;
    case 0x16: {
        s32 id = self->unk5C;
        if (self->msg) { fn_800BF830(self->msg); self->msg->exit(); self->msg = 0; }
        Message* m = fn_800BEEB8(1, id, 5, self->arr60, self->parent->scene, 0x14, 0, 0x2a, 0x2b, 0, 0, 0xf0);
        self->msg = m;
        m->unk120 = 1;
        fn_800BF97C(self->msg, self->unk5C, 0x10);
        fn_800BFA04(self->msg, self->unk5C, 0x11);
        self->state = 0x17;
        break;
    }
    case 0x17:
        if (self->msg->status == 3) {
            self->unk74 = self->msg->unk100;
            self->state = 0x18;
        }
        break;
    case 0x18: {
        if (self->msg) { fn_800BF830(self->msg); self->msg->exit(); self->msg = 0; }
        if (self->unk74 == 1) {
            u8 f = self->unk48;
            self->state = 0x37;
            self->unk48 = (u8)(f & 0xe0);
        }
        if (self->unk74 == 0) self->state = 0x3b;
        break;
    }
    case 0x19: {
        s32 entry, r;
        goto test_entry;
    next_entry:
        self->unk50++;
    test_entry:
        entry = *(s32*)((char*)self->unk4C + self->unk50 * 12);
        if (entry == 1 && self->unk58 == 1) r = 0;
        else if (entry == 2 && self->unk58 == 1) r = 0;
        else r = 1;
        if (r == 0) goto next_entry;
        self->unk54 = entry;
        if (entry == 6) self->state = 0x37;
        else if (entry == 0) { self->unk58 = 1; self->state = 0x1a; }
        else if (entry == 4) self->state = 0x33;
        else self->state = 0x1a;
        break;
    }
    case 0x1a: {
        shared_id = self->unk5C;
        s32 k = self->unk54 + 6;
        if (self->msg) { fn_800BF830(self->msg); self->msg->exit(); self->msg = 0; }
        Message* m = fn_800BEEB8(1, shared_id, k, self->arr60, self->parent->scene, 0x14, 0, 0x2a, 0x2b, 0, 0, 0xf0);
        self->msg = m;
        m->unk120 = 1;
        fn_800BF97C(self->msg, self->unk5C, 0xe);
        fn_800BFA04(self->msg, self->unk5C, 0xf);
        self->state = 0x1b;
        break;
    }
    case 0x1b:
        if (self->msg->status == 3) {
            self->unk74 = self->msg->unk100;
            self->state = 0x1c;
        }
        break;
    case 0x1c:
        if (self->msg) { fn_800BF830(self->msg); self->msg->exit(); self->msg = 0; }
        if (self->unk74 == 1) {
            if (self->unk54 == 0) self->state = 0x2e;
            else self->state = 0x1d;
        }
        if (self->unk74 == 0) self->state = 0x2b;
        break;
    case 0x1d: {
        shared_id = self->unk5C;
        if (self->msg) { fn_800BF830(self->msg); self->msg->exit(); self->msg = 0; }
        Message* m = fn_800BEEB8(3, shared_id, 1, self->arr60, self->parent->scene, 0x14, -1, 0x2a, 0x2b, 0, 0, 0xf0);
        self->msg = m;
        m->unk120 = 1;
        fn_800309F8(self->res, 0x2b, ((s32*)self->unk4C)[self->unk50 * 3]);
        Scene* sc = self->parent->scene;
        sc->attach(sc->fieldE4, self->obj->model);
        fn_800B753C(self->obj, lbl_22_rodata_0);
        self->state = 0x1e;
        break;
    }
    case 0x1e:
        if (g_gfHomeMenu->setBan(1, 0) == 1U) self->state = 0x1f;
        break;
    case 0x1f:
        if (self->res->f0 == 0) {
            fn_800BF828(self->msg, 2);
            Scene* sc = self->parent->scene;
            sc->detach(self->obj->model);
            self->state = 0x20;
        }
        break;
    case 0x20:
        if (self->msg->status == 3) self->state = 0x21;
        break;
    case 0x21:
        g_gfHomeMenu->setBan(0, 0);
        if (self->msg) { fn_800BF830(self->msg); self->msg->exit(); self->msg = 0; }
        switch (self->res->a0) {
        case 0: self->state = 0x22; break;
        case 1: self->state = 0x25; break;
        case 2: self->state = 0x28; break;
        case 3:
            OSReport(base + 0x40);
            self->state = 0x3c;
            break;
        }
        break;
    case 0x22: {
        s32 k = self->unk54 + 0xa;
        s32 id = self->unk5C;
        if (self->msg) { fn_800BF830(self->msg); self->msg->exit(); self->msg = 0; }
        Message* m = fn_800BEEB8(0, id, k, self->arr60, self->parent->scene, 0x14, 0, 0x2a, 0x2b, 0, 0, 0xf0);
        self->msg = m;
        m->unk120 = 1;
        self->state = 0x23;
        break;
    }
    case 0x23:
        if (self->msg->status == 3) self->state = 0x24;
        break;
    case 0x24: {
        if (self->msg) { fn_800BF830(self->msg); self->msg->exit(); self->msg = 0; }
        s32 c = self->unk50;
        self->state = 0x19;
        self->unk50 = c + 1;
        break;
    }
    case 0x25: {
        shared_id = self->unk5C;
        if (self->msg) { fn_800BF830(self->msg); self->msg->exit(); self->msg = 0; }
        Message* m = fn_800BEEB8(0, shared_id, 3, self->arr60, self->parent->scene, 0x14, 0, 0x2a, 0x2b, 0, 0, 0xf0);
        self->msg = m;
        m->unk120 = 1;
        self->state = 0x26;
        break;
    }
    case 0x26:
        if (self->msg->status == 3) self->state = 0x27;
        break;
    case 0x27:
        if (self->msg) { fn_800BF830(self->msg); self->msg->exit(); self->msg = 0; }
        self->state = 0x2b;
        break;
    case 0x28: {
        s32 k = self->unk54 + 0x12;
        s32 id = self->unk5C;
        if (self->msg) { fn_800BF830(self->msg); self->msg->exit(); self->msg = 0; }
        Message* m = fn_800BEEB8(0, id, k, self->arr60, self->parent->scene, 0x14, 0, 0x2a, 0x2b, 0, 0, 0xf0);
        self->msg = m;
        m->unk120 = 1;
        self->state = 0x29;
        break;
    }
    case 0x29:
        if (self->msg->status == 3) self->state = 0x2a;
        break;
    case 0x2a:
        if (self->msg) { fn_800BF830(self->msg); self->msg->exit(); self->msg = 0; }
        self->state = 0x2b;
        break;
    case 0x2b: {
        s32 k = self->unk54 + 0x16;
        s32 id = self->unk5C;
        if (self->msg) { fn_800BF830(self->msg); self->msg->exit(); self->msg = 0; }
        Message* m = fn_800BEEB8(1, id, k, self->arr60, self->parent->scene, 0x14, 0, 0x2a, 0x2b, 0, 0, 0xf0);
        self->msg = m;
        m->unk120 = 1;
        fn_800BF97C(self->msg, self->unk5C, 0x10);
        fn_800BFA04(self->msg, self->unk5C, 0x11);
        self->state = 0x2c;
        break;
    }
    case 0x2c:
        if (self->msg->status == 3) {
            self->unk74 = self->msg->unk100;
            self->state = 0x2d;
        }
        break;
    case 0x2d: {
        if (self->msg) { fn_800BF830(self->msg); self->msg->exit(); self->msg = 0; }
        self->unk50 = self->unk50 + 1;
        if (self->unk74 == 1) {
            self->unk48 &= ~(1 << self->unk54);
            if (self->unk54 == 0) self->unk48 = (u8)(self->unk48 & 0xf8);
            self->state = 0x19;
        }
        if (self->unk74 == 0) self->state = 0x3b;
        break;
    }
    case 0x2e: {
        s32 id = self->unk5C;
        if (self->msg) { fn_800BF830(self->msg); self->msg->exit(); self->msg = 0; }
        Message* m = fn_800BEEB8(3, id, 1, self->arr60, self->parent->scene, 0x14, -1, 0x2a, 0x2b, 0, 0, 0xf0);
        self->msg = m;
        m->unk120 = 1;
        self->unk54 = 0;
        fn_800309F8(self->res, 0x2b, 7);
        Scene* sc = self->parent->scene;
        sc->attach(sc->fieldE4, self->obj->model);
        fn_800B753C(self->obj, lbl_22_rodata_0);
        self->state = 0x2f;
        break;
    }
    case 0x2f:
        if (g_gfHomeMenu->setBan(1, 0) == 1U) self->state = 0x30;
        break;
    case 0x30:
        if (self->res->f0 == 0) {
            fn_800BF828(self->msg, 2);
            Scene* sc = self->parent->scene;
            sc->detach(self->obj->model);
            self->state = 0x31;
        }
        break;
    case 0x31:
        if (self->msg->status == 3) self->state = 0x32;
        break;
    case 0x32:
        g_gfHomeMenu->setBan(0, 0);
        if (self->msg) { fn_800BF830(self->msg); self->msg->exit(); self->msg = 0; }
        self->unk54 = 0;
        switch (self->res->a0) {
        case 0: self->state = 0x22; break;
        case 1: self->state = 0x25; break;
        case 2: self->state = 0x28; break;
        case 3:
            OSReport(base + 0x60);
            self->state = 0x3c;
            break;
        }
        break;
    case 0x33:
        fn_800309F8(self->res, 0x2b, 4);
        self->state = 0x34;
        break;
    case 0x34:
        if (g_gfHomeMenu->setBan(1, 0) == 1U) self->state = 0x35;
        break;
    case 0x35:
        if (self->res->f0 == 0) self->state = 0x36;
        break;
    case 0x36: {
        g_gfHomeMenu->setBan(0, 0);
        self->unk50 = self->unk50 + 1;
        s32 a = self->res->a0;
        switch (a) {
        case 0: self->state = 0x19; break;
        case 1: case 2: case 3:
            OSReport(base + 0x80);
            self->state = 0x19;
            break;
        }
        break;
    }
    case 0x37:
        fn_8004EAE0((void**)g_GameGlobal, self->unk48);
        if (fn_800305B0(0) == 1U) self->state = 0x38;
        else self->state = 0x3d;
        break;
    case 0x38:
        fn_80030F64(self->res, 0x2b);
        self->state = 0x39;
        break;
    case 0x39:
        if (self->res->f0 == 0) self->state = 0x3a;
        break;
    case 0x3a:
        if (self->res->a0 == 0) {
            fn_8004EB20(g_GameGlobal, self->res->handle.getBuffer());
            free__13gfHeapManagerFPv(self->res->handle.getBuffer());
            self->state = 0x3d;
        } else {
            OSReport(base + 0x98);
            self->state = 0x3c;
        }
        break;
    case 0x3b:
        g_gfShutdownManager.enterReturnToWiiMenuProcess();
        self->state = 0x3d;
        break;
    case 0x3c: {
        OSReport(base + 0xb0);
        u8 f = (u8)(self->unk48 & 0xe0);
        self->unk48 = f;
        fn_8004EAE0((void**)g_GameGlobal, f);
        self->state = 0x3d;
        break;
    }
    case 0x3d:
    case 0x3e:
        break;
    }
    self->count = self->count + 1;
}