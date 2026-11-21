#include <gf/gf_homemenu.h>
#include <gf/gf_shutdown_manager.h>
#include <gm/gm_global.h>
#include <mu/mu_msg.h>
#include <string.h>
#include <types.h>
#pragma force_active on

class VObj {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13(void*);
};

struct Target {
    char pad[0x11c];
    char name[0x234];
    int state;
    int result;
};

struct Other {
    char pad[0x10];
    void* value;
};

struct Self {
    char pad0[0x40];
    VObj* object;
    char pad44[0x14];
    Other* other;
    char pad5c[4];
    int result;
    char pad64[4];
    int value;
    char pad6c[4];
    int mode;
    char pad74[0x18];
    MuMsg* msg;
    char pad90[8];
    int state;
    char entry[0x10];
    Target* target;
    unsigned char enabled;
    char padb1[0x1f];
    int type;
    char padd4[4];
    unsigned char flag;
};

extern "C" {
unsigned int fn_80153810(void*);
char* fn_80153D50(void*);
void fn_800C6EC0(Target*, int*, unsigned int, char*);
void fn_800C6E9C(Target*, int, unsigned int, char*);
void fn_800C70A4(Target*, int*);
void fn_80055934(int);
extern char lbl_8059E3D4[4];
}

extern "C" int fn_800F4708(Self* self) {
            bool a;
    gmStageEditData* data;

    switch (self->state) {
    case 0:
        if (g_gfHomeMenu->setBan(1, 5) && self->target->state == 0) {
            if (self->flag) {
                data = g_GameGlobal->m_stageEditData;
                int equal = (self->value == 0) == (*(int*)((char*)data + 0x24a0) == 0);
                *(unsigned char*)((char*)data + 0x249c) = equal;
                self->flag = equal;
            }

            int a = fn_80153810(self->entry);
            char* b = fn_80153D50(self->entry);
            if (self->flag) {
                fn_800C6EC0(
                    self->target,
                    (int*)((char*)g_GameGlobal->m_stageEditData + 0x24a0),
                    a, b);
            } else {
                fn_800C6E9C(self->target, self->value != 0, a, b);
            }
            self->state = 1;
        }
        break;

    case 1: {
        Target* target = self->target;
        if (target->state == 0) {
            data = g_GameGlobal->m_stageEditData;
            a = target->result == 0;
            if (self->flag && a) {
                fn_800C70A4(target, (int*)((char*)data + 0x24a0));
                self->state = 2;
            } else {
                self->enabled = 1;
                self->state = 3;
            }

            if (a || self->target->result == 1) {
                if (self->type == 2 && !self->flag) {
                    fn_80055934(1);
                }
                if (a) {
                    *(unsigned char*)((char*)data + 0x249c) = 1;
                    self->flag = 1;
                    *(int*)((char*)data + 0x24a0) = self->value != 0;
                    strcpy((char*)data + 0x24a4, self->target->name);
                }
            } else {
                *(unsigned char*)((char*)data + 0x249c) = 0;
                self->flag = 0;
            }
        }
        break;
    }

    case 2:
        if (self->target->state == 0) {
            self->enabled = 1;
            self->state = 3;
        }
        break;
    }

    if (self->state != 3) {
        return self->result;
    }
    if (self->mode == 8 || self->mode == 3) {
        return self->result;
    }

    self->object->s13(self->other->value);
    self->msg->printf(3, lbl_8059E3D4);

    if (self->target->result != 0 && self->target->result != 1) {
        g_gfHomeMenu->setBan(0, 5);
        g_gfShutdownManager.unkD = true;
        return 5;
    }
    return 10;
}
