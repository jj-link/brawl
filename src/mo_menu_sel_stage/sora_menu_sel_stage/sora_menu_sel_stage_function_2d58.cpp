#include <types.h>
#include <mu/mu_object.h>
#pragma force_active on

struct Animation {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void setFrame(float);
};
struct Entry {
    unsigned char flags : 1;
    unsigned char rest : 7;
    char pad[3];
    int index;
    int value;
};
struct Option {
    u8 active;
    char pad[7];
};
struct Self {
    char pad0[0x40];
    int mode;
    char pad1[0x1f4 - 0x44];
    MuObject* object;
    char pad2[0x228 - 0x1f8];
    int selected;
    char pad3[4];
    Option options[2];
    char pad4[4];
    int flag;
    char pad5[4];
    int index;
    char pad6[0x28c - 0x250];
    Entry entries[2000];
    int count;
    char pad7[0x605c - 0x6050];
    int previous0;
    int previous1;
    char pad8[0x6088 - 0x6064];
    float timer;
    int state;
};

extern "C" {
extern void* lbl_11_bss_8;
extern const float lbl_11_rodata_0;
extern u8 lbl_11_rodata_128[];
int fn_11_7CD0(void*, int);
int fn_11_7CF0(void*, int, int);
void fn_11_2F04(Self*);
void fn_11_1B70(Self*, float);

inline u8 optionActive(Self* self, unsigned int index) {
    if (index <= 1)
        return self->options[index].active;
    return 0;
}

void fn_11_2D58(Self* self) {
    MuObject* object;
    int one = fn_11_7CD0(lbl_11_bss_8, 1);
    int zero = fn_11_7CD0(lbl_11_bss_8, 0);
    if (one != self->previous1 || zero != self->previous0) {
        fn_11_2F04(self);
        float frame = lbl_11_rodata_0;
        self->state = 0;
        self->timer = frame;
        fn_11_1B70(self, frame);
        Entry* entry = self->entries;
        for (int i = 0; i < 6; ++i, ++entry) {
            if (entry->value == -1)
                entry->value = fn_11_7CF0(lbl_11_bss_8, entry->flags == 1, entry->index);
        }
        self->previous1 = one;
        object = self->object;
        self->previous0 = zero;
        one = self->selected;
        ((Animation*)object->m_modelAnim->m_anmObjTexPatRes)->setFrame(lbl_11_rodata_0);
        do {
            ++one;
            if (one >= 3)
                one = 0;
            if ((unsigned int)one <= 1) {
                if (optionActive(self, one))
                    break;
            } else if (self->mode == 0 && self->count > 0) {
                break;
            }
        } while (true);
        object->setFrameTex((float)lbl_11_rodata_128[one]);
        self->index = -1;
        if (self->selected == 2)
            self->flag = 1;
    }
}
}