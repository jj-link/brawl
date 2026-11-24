#include <ut/ut_list.h>
#include <mu/mu_object.h>
#include <string.h>
#include <stdio.h>
#include <types.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8(float);
    virtual void slot9();
    virtual void slot10();
    virtual void slot11(void*, void*);
    char pad[0xe4 - 4];
    void* layer;
};

struct Manager {
    char pad0[0x1bc];
    int priority;
    char pad1c0[8];
    nw4r::g3d::ResFile resource;
    char pad1cc[0x27c - 0x1cc];
    Object_vptr_0* scene;
};

struct Name { char s[65]; };
struct Triple { int x, y, z; };

struct Self {
    utListNode node;
    utList* list;
    void* link;
    union {
        unsigned int flags;
        struct { unsigned char byte; char pad[3]; } b;
        struct { u8 high : 4; u8 hidden : 1; u8 visible : 1; u8 low : 2; } bits;
    };
    void* vtable;
    MuObject* object;
    int kind;
    int a;
    int b2;
    Triple pos;
    Triple rot;
};

extern "C" {
extern utList lbl_8049E560;
extern char lbl_8045CBC0[];
extern const char* lbl_8045C8C4[];
extern Manager* lbl_805A0310;
extern char lbl_8059E480[3];
extern char lbl_8059E484[3];
extern const float lbl_805A2770;
int fn_800B66A0(MuObject*);
}

extern "C" Self* fn_800FFE6C(Self* self, int kind, int a, int b, const Triple& pos, const Triple& rot) {
    MuObject* object;
    Name n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12;
    self->list = 0;
    self->node.m_next = 0;
    self->node.m_prev = 0;
    lbl_8049E560.addTail(&self->node);
    self->flags &= 0x0fffffff;
    self->list = &lbl_8049E560;
    self->link = 0;
    self->bits.hidden = 0;
    self->bits.visible = 1;
    self->vtable = lbl_8045CBC0;
    self->object = 0;
    self->kind = kind;
    self->a = a;
    self->b2 = b;
    self->pos = pos;
    self->rot = rot;
    Manager* manager = lbl_805A0310;
    MuObject* obj = MuObject::create(&manager->resource, lbl_8045C8C4[kind], manager->priority, 0, (HeapType)0x2a);
    if (obj) manager->scene->slot11(manager->scene->layer, obj->m_sceneModel);
    MuObject* old = self->object;
    if (old != obj) {
        delete old;
        self->object = obj;
    }
    switch (kind) {
    case 7:
    case 8:
        {
            object = self->object;
            char* mdl = *(char**)((char*)object + 8);
            int off = *(int*)(mdl + 0x3c);
            const char* src = off ? mdl + off : 0;
            n1.s[0] = 0;
            strcat(n1.s, src);
            n2 = n1;
            strcat(n2.s, lbl_8059E484);
            n3 = n2;
            sprintf(n3.s + strlen(n3.s), lbl_8059E480, 0);
            n4 = n3;
            object->changeNodeAnimNIf(n4.s);
        }
        {
            object = self->object;
            char* mdl = *(char**)((char*)object + 8);
            int off = *(int*)(mdl + 0x3c);
            const char* src = off ? mdl + off : 0;
            n5.s[0] = 0;
            strcat(n5.s, src);
            n6 = n5;
            strcat(n6.s, lbl_8059E484);
            n7 = n6;
            sprintf(n7.s + strlen(n7.s), lbl_8059E480, 0);
            n8 = n7;
            object->changeClrAnimNIf(n8.s);
        }
        {
            object = self->object;
            char* mdl = *(char**)((char*)object + 8);
            int off = *(int*)(mdl + 0x3c);
            const char* src = off ? mdl + off : 0;
            n9.s[0] = 0;
            strcat(n9.s, src);
            n10 = n9;
            strcat(n10.s, lbl_8059E484);
            n11 = n10;
            sprintf(n11.s + strlen(n11.s), lbl_8059E480, 0);
            n12 = n11;
            object->changeVisAnimNIf(n12.s);
        }
        Object_vptr_0* anim = *(Object_vptr_0**)((char*)self->object->m_modelAnim + 8);
        anim->slot8(lbl_805A2770);
        int frame = 0;
        self->object->setFrameVisible((float)frame);
        break;
    }
    int visible = fn_800B66A0(self->object);
    self->bits.visible = visible;
    return self;
}
