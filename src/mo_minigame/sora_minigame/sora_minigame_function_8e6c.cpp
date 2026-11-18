#include <types.h>
#include <nw4r/g3d/g3d_obj.h>
#pragma force_active on

struct Obj {
    virtual ~Obj();
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
    u8 pad[0x1C];
    u8 flag;
};

struct Mgr {
    u8 pad0[0x43];
    u8 f43;
    u8 pad1[0x244 - 0x44];
    Obj* slots[5][7];
    Obj* x2D0;
    u8 pad2[0x371 - 0x2D4];
    u8 f371;
    u8 pad3[0x3B0 - 0x372];
    nw4r::g3d::G3dObj* ptrs[5][6];
    u8 flags[5][6];
    u8 pad4[0x4D0 - 0x446];
    Obj** p4D0;
    u8 pad5[0x4F4 - 0x4D4];
    Obj** arr;
    s32 count;
};

extern "C" void fn_20_8E6C(Mgr* self) {
    for (s32 i = 0; i < self->count; i++) {
        Obj* obj = self->arr[i];
        obj->v18();
        obj->flag = 0;

        for (s32 k = 0; k < 5; k++) {
            for (s32 j = 0; j < 7; j++) {
                if (self->slots[k][j] == obj)
                    self->slots[k][j] = 0;
            }
        }

        if (self->x2D0 == obj)
            self->x2D0 = 0;

        s32 cnt = --self->count;
        self->arr[i] = self->arr[cnt];

        if (self->f43 != 0 || *self->p4D0 != obj) {
            delete obj;
        }
    }

    if (self->f371 != 0)
        self->f371 = 0;

    for (s32 a = 0; a < 5; a++) {
        for (s32 b = 0; b < 6; b++) {
            if (self->ptrs[a][b] != 0 && self->flags[a][b] != 0) {
                self->ptrs[a][b]->Destroy();
                self->flags[a][b] = 0;
                self->ptrs[a][b] = 0;
            }
        }
    }
}
