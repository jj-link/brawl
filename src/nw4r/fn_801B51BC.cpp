#include <types.h>
#include <nw4r/g3d/g3d_scnmdlsmpl.h>
#pragma force_active on

extern "C" void fn_801ABA14(void*, int, int, void*);
extern int lbl_8059E950;

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1(u32, void*, int, void*);
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
};

class SceneObject {
public:
    virtual void slot0();
    virtual void slot1(u32, int, void*);
};

class Class_80466500 {
public:
    virtual void fn_801B5520();
    virtual void fn_801B51BC();
    virtual void fn_801B54A4();
    virtual void fn_801B55B8();
    virtual void fn_801B5588();
    virtual void fn_801AB788();
    virtual void fn_801AAC9C();
    virtual void fn_801AAE34();
    virtual void fn_801AAFDC();
    virtual void fn_801AAFE8();
    virtual void fn_801AAA70(void*, int*);
    u8 pad0[0x38];
    u8 matrix[0x30];
    u8 pad1[0x60];
    u32 mask;
    u8 pad2[4];
    Object_vptr_0* handler;
    u8 timing;
    u8 pad3;
    u16 flags;
    SceneObject** children;
    u8 pad4[4];
    u32 count;
    nw4r::g3d::ScnMdlSimple* model;
    u32* indices;
};

inline void callback(Class_80466500* self, int timing, int param, void* info) {
    if (self->handler && (self->flags & 1) && (self->timing & timing))
        self->handler->slot1(timing, self, param, info);
}

extern "C" void fn_801B51BC(Class_80466500* self, int task, int param, void* info) {
    int masked;
    if ((u32)task < 9U && ((1U << (task - 1)) & self->mask))
        masked = 1;
    else
        masked = 0;
    if (masked != 0)
        return;

    switch (task) {
    case 1: {
        if (self->handler && (self->flags & 1) && (self->timing & 1))
            self->handler->slot1(1, self, param, info);
        self->fn_801AAA70(info, &param);
        callback(self, 2, param, info);
        if (self->model)
            ((SceneObject*)self->model)->slot1(task, param, self->matrix);
        SceneObject* child;
        u32 offset;
        u32 count = self->count;
        u32 i = 0;
        offset = 0;
        for (; i < count; offset += 4, i++) {
            u32 index = *(u32*)((u8*)self->indices + offset);
            int childParam = param;
            if (index != (u32)lbl_8059E950) {
                child = *(SceneObject**)((u8*)self->children + offset);
                nw4r::math::MTX34 mtx;
                if (self->model) {
                    if (!self->model->GetScnMtxPos(&mtx, nw4r::g3d::ScnObj::MTX_WORLD, index))
                        childParam |= 1;
                } else {
                    childParam |= 1;
                }
                child->slot1(task, childParam, &mtx);
            }
        }
        callback(self, 4, param, info);
        break;
    }
    case 0x10002:
    case 0x10003:
        fn_801ABA14(self, task, param, info);
        break;
    case 0x10001:
        if (info == self->model) {
            ((SceneObject*)self->model)->slot1(0x10003, 0, self);
            self->model = 0;
        } else {
            fn_801ABA14(self, task, param, info);
        }
        break;
    default:
        if (self->model)
            ((SceneObject*)self->model)->slot1(task, param, info);
        fn_801ABA14(self, task, param, info);
        break;
    }
}
