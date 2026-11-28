#pragma force_active on
#define FT bool

#include <types.h>
#include <gm/gm_global.h>

extern "C" {
extern char __files[];
extern char lbl_40_data_17D98[];

int fn_803F86E4(void *, const char *, ...);
void fn_803FC984(void);
int exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(int);
int fn_40_3EC48(int, FT *, FT *, FT *);
}

struct Bits {
    unsigned int words[2];
    bool test(unsigned int i) const {
        if (i >= 51) {
            fn_803F86E4(__files + 0xA0, lbl_40_data_17D98);
            fn_803FC984();
        }
        return (words[i >> 5] & (1 << (i & 31))) != 0;
    }
};

struct AdvData {
    char pad[0x4898];
    Bits bits;
    char pad2[8];
    Bits groups[10];
};


static inline int find_kind_group(int slot, int ordinal)
{
    AdvData *adv = (AdvData *)g_GameGlobal->m_advData;
    int index;
    int count = 0;
    for (index = 0; index < 50; index++) {
        if (adv->groups[slot].test(index)) {
            if (count == ordinal)
                return exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(index);
            count++;
        }
    }
    return 0x28;
}

static inline int find_kind(int ordinal)
{
    int index;
    int count = 0;
    AdvData *adv = (AdvData *)g_GameGlobal->m_advData;
    for (index = 0; index < 50; index++) {
        if (adv->bits.test(index)) {
            if (count == ordinal)
                return exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(index);
            count++;
        }
    }
    return 0x28;
}

struct Group {
    int id;
    int kinds[40];
    int count;
    int pad;
};

struct Obj {
    char pad[0x40];
    Group groups[10];
    int total;
    char pad2[0xC2C - 0x6FC];
    unsigned char fC2C;
    unsigned char fC2D;
    unsigned char fC2E;
    char pad3[5];
    int fC34;
    int fC38;
};

static inline void mark(Obj *self, int kind)
{
    self->fC2C |= kind == 28 ? 1 : (kind == 29 ? 2 : (kind == 30 ? 4 : 0));
    self->fC2D |= kind == 14 ? 1 : (kind == 15 ? 2 : 0);
    self->fC2E |= kind == 3 ? 1 : (kind == 4 ? 2 : 0);
}

extern "C" void fn_40_3E6A8(Obj *self, const unsigned int *arg1)
{
    int total = 0;
    FT spA = 0;
    int initial = *arg1;
    FT sp9 = 0;
    FT sp8 = 0;
    int i;
    int j;
    int count;

    if (initial != 0) {
        for (i = 0; i < 10; i++) {
            if (*arg1 & (1 << i)) {
                for (j = 0; j < 40; j++) {
                    int kind = find_kind_group(i, j);
                    if (kind == 0x28)
                        break;
                    mark(self, kind);
                }
            }
        }

        count = 0;
        for (i = 0; i < 10; i++) {
            if (*arg1 & (1 << i)) {
                if (*arg1 & 0x400)
                    self->groups[total].id = 0;
                else {
                    self->groups[total].id = i;
                    count = 0;
                }

                for (j = 0; j < 40; j++) {
                    int kind = find_kind_group(i, j);
                    if (kind == 0x28)
                        break;
                    kind = fn_40_3EC48(kind, &spA, &sp9, &sp8);
                    if (kind != 0x28) {
                        self->groups[total].kinds[count] = kind;
                        count++;
                    }
                }

                if (!(*arg1 & 0x400) && count > 0) {
                    self->groups[total].count = count;
                    total++;
                }
            }
        }

        if ((*arg1 & 0x400) && count > 0) {
            self->groups[total].count = count;
            total++;
        }
        self->total = total;
    } else {
        for (j = 0; j < 40; j++) {
            int kind = find_kind(j);
            if (kind == 0x28)
                break;
            mark(self, kind);
        }

        self->groups[0].id = 0;
        count = 0;
        for (j = 0; j < 40; j++) {
            int kind = find_kind(j);
            if (kind == 0x28)
                break;
            kind = fn_40_3EC48(kind, &spA, &sp9, &sp8);
            if (kind != 0x28) {
                self->groups[0].kinds[count] = kind;
                count++;
            }
        }

        if (count > 0) {
            self->groups[0].count = count;
            total = 1;
        }
        self->total = total;
    }

    if (self->fC2D == 2)
        self->fC34 = 0xF;
    else
        self->fC34 = 0xE;
    if (self->fC2E == 2)
        self->fC38 = 4;
    else
        self->fC38 = 3;

    if (self->total <= 0) {
        self->groups[0].id = 0;
        self->groups[0].kinds[0] = 0;
        self->groups[0].count = 1;
        self->total = 1;
    }
}
