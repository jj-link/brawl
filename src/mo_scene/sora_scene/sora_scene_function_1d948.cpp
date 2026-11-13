#include <gm/gm_global.h>
#include <mu/mu_msg.h>
#include <types.h>

#pragma force_active on

struct UnkParam {
    union {
        bool asBool;
        u32 asInt;
    } unk0;
    u32 unk4;
};

struct NameKey {
    char name[6];
};

struct SceneChild {
    char pad00[0x40];
    s32 status;
    char pad44[0xC8];
    s32 unk10C;
    char pad110[0x4];
    s32 unk114;
    char pad118[0x1F6];
    char buf30E[1];
};

struct SceneObj {
    char pad00[0x40];
    s32 status;
    char pad44[0xC];
    s32 unk50;
    char pad54[0x168];
    s32 unk1BC;
    MuMsg* msg;
    char pad1C4[0x305];
    char buf4C9[1];
    char pad4CA[0x102];
    s32 unk5CC;
};

struct SceneTask {
    char pad00[0x8];
    SceneObj* obj;
    char pad0C[0x4];
    SceneChild* child;
    char pad14[0x8];
    s32 result;
    char pad20[0x8];
    s32 unk28;
    char pad2C[0x4];
    s32 unk30;
    char pad34[0x18];
    s32* unk4C;
};

extern "C" {
extern NameKey lbl_1_rodata_8F0;
extern char lbl_1_data_616C[9];
extern char lbl_1_data_6290[4];
extern char lbl_1_data_6294[4];
extern char lbl_1_data_6298[5];
extern char lbl_1_data_62A0[5];
extern char lbl_1_data_62A8[5];
extern char lbl_1_data_62B0[5];

SceneChild* fn_28_0(s32* arr, u32 v);
void exit__6gfTaskFv(SceneChild* task);
s32 getLanguage__10GameGlobalFv(GameGlobal* self);
int sprintf(char* dst, const char* fmt, ...);
char* strcat(char* dst, const char* src);
char* strcpy(char* dst, const char* src);
int strcmp(const char* a, const char* b);
}

extern "C" s32 fn_1_1D948(SceneTask* self) {
    char sAC[0x1C];
    char s90[0x1C];
    char s74[0x1C];
    char s58[0x1C];
    s32 arr[4];
    UnkParam defA;
    UnkParam a;
    UnkParam c;
    UnkParam defD;
    UnkParam d;
    UnkParam e;
    NameKey key1;
    NameKey key2;
    SceneObj* obj;
    s32 v10c;
    SceneChild* child;
    s32 ret = self->result;
    s32 done = 0;

    if (self->child == NULL) {
        SceneChild* created;

        arr[0] = 0;
        arr[1] = 0;
        arr[2] = 0;
        arr[3] = 0;
        char* adv = (char*)g_GameGlobal->m_advData;
        if (adv != NULL) {
            a.unk0.asInt = *(u32*)(adv + 0x4928);
            a.unk4 = *(u32*)(adv + 0x492C);
        } else {
            defA.unk0.asBool = false;
            defA.unk4 = -1;
            a = defA;
        }
        c = a;
        arr[1] = c.unk4;
        if (g_GameGlobal->m_advData != NULL) {
            d.unk0.asInt = *(u32*)((char*)g_GameGlobal->m_advData + 0x4930);
            d.unk4 = *(u32*)((char*)g_GameGlobal->m_advData + 0x4934);
        } else {
            defD.unk0.asBool = false;
            defD.unk4 = -1;
            d = defD;
        }
        e = d;
        arr[2] = e.unk4;
        created = fn_28_0(arr, e.unk0.asInt);
        self->child = created;
        created->unk10C = self->unk28;
        self->child->unk114 = self->unk30;
    }

    child = self->child;
    switch (child->status) {
    case 2: {
        s32 flag;
        obj = self->obj;
        v10c = child->unk10C;
        self->unk28 = v10c;
        self->unk30 = child->unk114;
        obj->unk5CC = v10c;
        self->obj->unk50 = self->child->unk114;
        if (self->unk28 == 0 && self->unk30 == 0) {
            SceneObj* o1 = self->obj;
            key1 = lbl_1_rodata_8F0;
            const char* name = lbl_1_data_616C;
            if (getLanguage__10GameGlobalFv(g_GameGlobal) == 0) {
                sprintf(s90, lbl_1_data_62B0);
                sprintf(sAC, lbl_1_data_62A8);
            } else {
                sprintf(s90, lbl_1_data_62A0);
                sprintf(sAC, lbl_1_data_6298);
            }
            sprintf(s90, lbl_1_data_6294);
            sprintf(sAC, lbl_1_data_6290);
            if (strcmp(key1.name, name) == 0) {
                o1->msg->printIndex(4, 0x22, NULL);
            } else {
                strcat(s90, name);
                o1->msg->printf(4, s90);
                strcpy(o1->buf4C9, s90);
            }
        } else {
            char* txt = self->child->buf30E;
            SceneObj* o2 = self->obj;
            key2 = lbl_1_rodata_8F0;
            if (getLanguage__10GameGlobalFv(g_GameGlobal) == 0) {
                sprintf(s58, lbl_1_data_62B0);
                sprintf(s74, lbl_1_data_62A8);
            } else {
                sprintf(s58, lbl_1_data_62A0);
                sprintf(s74, lbl_1_data_6298);
            }
            if (strcmp(key2.name, txt) == 0) {
                o2->msg->printIndex(4, 0x22, NULL);
            } else {
                strcat(s58, txt);
                o2->msg->printf(4, s58);
                strcpy(o2->buf4C9, s58);
            }
        }
        {
            SceneObj* o = self->obj;
            s32 st = o->status;
            if (st == 2 || st == 3 || st == 4 || st == 8 || st == 9 || (u32)(st - 5) <= 1) {
                flag = 1;
            } else {
                flag = 0;
            }
            if (flag != 0) {
                o->status = 0;
                o->unk1BC = 10;
            }
        }
        ret = 1;
        done = 1;
        if (self->unk4C != NULL) {
            *self->unk4C = self->unk28 + self->unk30;
        }
        break;
    }
    case 3: {
        s32 flag;
        {
            SceneObj* o = self->obj;
            s32 st = o->status;
            if (st == 2 || st == 3 || st == 4 || st == 8 || st == 9 || (u32)(st - 5) <= 1) {
                flag = 1;
            } else {
                flag = 0;
            }
            if (flag != 0) {
                o->status = 0;
                o->unk1BC = 10;
            }
        }
        ret = 1;
        done = 1;
        break;
    }
    }

    if (done != 0) {
        exit__6gfTaskFv(self->child);
        self->child = NULL;
    }
    return ret;
}
