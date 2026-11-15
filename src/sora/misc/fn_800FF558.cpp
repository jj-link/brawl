#include <mu/mu_object.h>
#include <sr/sr_common.h>
#include <ut/ut_list.h>
#include <types.h>
#include <string.h>
#include <stdio.h>
#pragma force_active on
extern "C" {
extern void* lbl_805A0310;
extern utList lbl_8049E560;
extern char* lbl_8045C8C4[];
extern char lbl_8045CC40[];
extern char lbl_8059E480[3];
extern char lbl_8059E484[3];
extern float lbl_805A2770;
s32 fn_800B66A0(void*);
}
struct IfTable {
    void* unk0;
    void* unk4;
    void (*fn)(void*, int);
};
class Class_8042B6D0 {
public:
    virtual void fn_8004805C();
    virtual void fn_8004781C();
    virtual void fn_80046A28();
    virtual void fn_8004810C();
    virtual void fn_800480DC();
    virtual void fn_801AB1C4();
    virtual void fn_801B269C();
    virtual void fn_801B26E4();
    virtual void fn_801AAFDC();
    virtual void fn_801AAFE8();
    virtual void fn_801AB290();
    virtual void fn_801B2EEC(void*, void*);
    char pad[0xE0];
    void* fieldE4;
};
struct FlagBits { u8 other1 : 5; u8 bit : 1; u8 other2 : 2; };
struct Name { char s[0x41]; };
struct Node {
    utListNode node;
    utList* list;
    int unkC;
    unsigned int unk10;
    IfTable* ifTable;
    MuObject* object;
    int unk1C;
};
extern "C" Node* fn_800FF558(Node* self, int arg1, int type) {
    Name n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12;
    Name n13, n14, n15, n16, n17, n18, n19, n20, n21, n22, n23, n24;
    self->list = 0;
    self->node.m_next = 0;
    self->node.m_prev = 0;
    lbl_8049E560.addTail(&self->node);
    self->unk10 &= 0x0FFFFFFF;
    self->list = &lbl_8049E560;
    self->unkC = arg1;
    *(u8*)&self->unk10 = (*(u8*)&self->unk10 & ~8) | 4;
    self->ifTable = (IfTable*)lbl_8045CC40;
    self->object = 0;
    self->unk1C = type;
    char* g = (char*)lbl_805A0310;
    MuObject* obj = MuObject::create((nw4r::g3d::ResFile*)(g + 0x1c8),
                                     lbl_8045C8C4[type],
                                     *(int*)(g + 0x1bc),
                                     0, (Heaps::HeapType)0x2a);
    if (obj != 0) {
        Class_8042B6D0* m = *(Class_8042B6D0**)(g + 0x27c);
        m->fn_801B2EEC(m->fieldE4, obj->m_sceneModel);
    }
    MuObject* old = self->object;
    if (old != obj) {
        delete old;
        self->object = obj;
    }
    if (type >= 4) goto six;
    if (type >= 2) goto two;
    if (type >= 0) goto body1;
    goto end;
six:
    if (type == 6) goto store;
    goto end;
body1:
    {
        MuObject* o = self->object;
        char* mdl = *(char**)((char*)o + 8);
        int off = *(int*)(mdl + 0x3c);
        const char* nm = off != 0 ? mdl + off : 0;
        n1.s[0] = 0;
        strcat(n1.s, nm);
        n2 = n1;
        strcat(n2.s, lbl_8059E484);
        n3 = n2;
        sprintf(n3.s + strlen(n3.s), lbl_8059E480, 0);
        n4 = n3;
        o->changeNodeAnimNIf(n4.s);
    }
    {
        MuObject* o = self->object;
        char* mdl = *(char**)((char*)o + 8);
        int off = *(int*)(mdl + 0x3c);
        const char* nm = off != 0 ? mdl + off : 0;
        n5.s[0] = 0;
        strcat(n5.s, nm);
        n6 = n5;
        strcat(n6.s, lbl_8059E484);
        n7 = n6;
        sprintf(n7.s + strlen(n7.s), lbl_8059E480, 0);
        n8 = n7;
        o->changeClrAnimNIf(n8.s);
    }
    {
        MuObject* o = self->object;
        char* mdl = *(char**)((char*)o + 8);
        int off = *(int*)(mdl + 0x3c);
        const char* nm = off != 0 ? mdl + off : 0;
        n9.s[0] = 0;
        strcat(n9.s, nm);
        n10 = n9;
        strcat(n10.s, lbl_8059E484);
        n11 = n10;
        sprintf(n11.s + strlen(n11.s), lbl_8059E480, 0);
        n12 = n11;
        o->changeTexSrtAnimNIf(n12.s);
    }
    {
        MuObject* o = self->object;
        char* mdl = *(char**)((char*)o + 8);
        int off = *(int*)(mdl + 0x3c);
        const char* nm = off != 0 ? mdl + off : 0;
        n13.s[0] = 0;
        strcat(n13.s, nm);
        n14 = n13;
        strcat(n14.s, lbl_8059E484);
        n15 = n14;
        sprintf(n15.s + strlen(n15.s), lbl_8059E480, 0);
        n16 = n15;
        o->changeVisAnimNIf(n16.s);
    }
    self->object->m_modelAnim->m_anmObjVisRes->SetUpdateRate(lbl_805A2770);
    self->object->setFrameVisible((float)(int)(type != 0));
    goto end;
store:
    *(u8*)((char*)lbl_805A0310 + 0x1c4) = 1;
two:
    {
        MuObject* o = self->object;
        char* mdl = *(char**)((char*)o + 8);
        int off = *(int*)(mdl + 0x3c);
        const char* nm = off != 0 ? mdl + off : 0;
        n17.s[0] = 0;
        strcat(n17.s, nm);
        n18 = n17;
        strcat(n18.s, lbl_8059E484);
        n19 = n18;
        sprintf(n19.s + strlen(n19.s), lbl_8059E480, 0);
        n20 = n19;
        o->changeNodeAnimNIf(n20.s);
    }
    {
        MuObject* o = self->object;
        char* mdl = *(char**)((char*)o + 8);
        int off = *(int*)(mdl + 0x3c);
        const char* nm = off != 0 ? mdl + off : 0;
        n21.s[0] = 0;
        strcat(n21.s, nm);
        n22 = n21;
        strcat(n22.s, lbl_8059E484);
        n23 = n22;
        sprintf(n23.s + strlen(n23.s), lbl_8059E480, 0);
        n24 = n23;
        o->changeClrAnimNIf(n24.s);
    }
end:
    {
        int r = fn_800B66A0(self->object);
        ((FlagBits*)&self->unk10)->bit = r;
    }
    return self;
}
