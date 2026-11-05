#include <revolution/VF/pf_sector.h>

#pragma force_active on

typedef struct {
    unsigned short unk00;
    char pad02[0x1E];
    unsigned char unk20;
    char pad21[0x243];
    int unk264;
    int unk268;
} Node;

typedef struct {
    int unk00;
    int unk04;
    Node *node;
    int pad0C[4];
    unsigned int unk1C;
    int unk20;
    int unk24;
    unsigned short unk28;
} Obj;

extern int fn_803E1414(void *, int, int, void *);
extern void fn_803DAAE8(void *, int);

int fn_803E4210(Obj *self, void *buffer, int length, int *bytesWritten)
{
    int sp8;
    int var31;
    int r;
    int ptr;
    unsigned int n;
    unsigned int oldUnk20;
    unsigned int temp;
    unsigned int cand;

    *bytesWritten = 0;

    if (length == 0) {
        return 0;
    }

    if (self == 0) {
        var31 = 0;
    } else {
        var31 = self->node->unk268;
    }

    if ((unsigned int)length > (unsigned int)(((Node *)var31)->unk00 - self->unk28) ||
        (unsigned int)length > (unsigned int)((Node *)var31)->unk00) {
        return 0x1A;
    }

    if ((unsigned int)(self->unk20 + 0x10000) == 0xFFFF) {
        r = fn_803E1414((char *)self->node + 4, self->unk24, 0, (char *)self + 0x20);
        if (r != 0) {
            return r;
        }

        if ((unsigned int)(self->unk20 + 0x10000) == 0xFFFF) {
            self->unk1C = self->node->unk264;
            if (self == 0) {
                ptr = 0;
            } else {
                ptr = self->node->unk268;
            }
            self->unk24 = self->unk1C >> ((Node *)ptr)->unk20;
            self->unk28 = self->unk1C & (((Node *)ptr)->unk00 - 1);
            return 0x1C;
        }
    }

    r = PFSEC_WriteData((void *)var31, buffer, self->unk20, self->unk28, length, &sp8, 1);
    if (r != 0 && sp8 == 0) {
        return r;
    }

    *bytesWritten = sp8;
    oldUnk20 = self->unk20;
    n = sp8;
    if (self == 0) {
        ptr = 0;
    } else {
        ptr = self->node->unk268;
    }
    temp = self->unk28 + n;
    cand = oldUnk20 + (temp >> ((Node *)ptr)->unk20);
    if ((((Node *)ptr)->unk00 - 1) & temp) {
        self->unk20 = cand;
    } else {
        self->unk20 = -1;
    }

    self->unk1C += n;
    if (self->unk1C > (unsigned int)self->node->unk264) {
        self->node->unk264 = self->unk1C;
    }

    if (self == 0) {
        ptr = 0;
    } else {
        ptr = self->node->unk268;
    }
    self->unk24 = self->unk1C >> ((Node *)ptr)->unk20;
    self->unk28 = self->unk1C & (((Node *)ptr)->unk00 - 1);

    fn_803DAAE8(self, (int)cand);

    if ((unsigned int)sp8 != (unsigned int)length) {
        return r;
    }
    return 0;
}
