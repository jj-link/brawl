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
extern void fn_803E3614(void *, int, int);

int fn_803E3AD8(Obj *self, void *buffer, int length, int *bytesRead)
{
    int sp8;
    int var28;
    int r;
    int ptr;

    *bytesRead = 0;

    if (self == 0) {
        var28 = 0;
    } else {
        var28 = self->node->unk268;
    }

    if (length == 0) {
        return 0;
    }

    if ((unsigned int)(self->unk1C + length) >
        (unsigned int)self->node->unk264) {
        length = self->node->unk264 - self->unk1C;
        if (length == 0) {
            return 0;
        }
    }

    if ((unsigned int)(self->unk20 + 0x10000) == 0xFFFF) {
        r = fn_803E1414((char *)self->node + 4, self->unk24, 0,
                        (char *)self + 0x20);
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

        if ((unsigned int)(self->unk1C + length) >
            (unsigned int)self->node->unk264) {
            self->unk1C = self->node->unk264;
            if (self == 0) {
                ptr = 0;
            } else {
                ptr = self->node->unk268;
            }
            self->unk24 = self->unk1C >> ((Node *)ptr)->unk20;
            self->unk28 = self->unk1C & (((Node *)ptr)->unk00 - 1);
            return 0x1B;
        }
    }

    r = PFSEC_ReadData((void *)var28, buffer, self->unk20,
                       self->unk28, length, &sp8, 1);
    var28 = r;
    if (r != 0 && sp8 == 0) {
        return var28;
    }

    *bytesRead = sp8;
    fn_803E3614(self, sp8, self->unk20);

    if ((unsigned int)sp8 != (unsigned int)length) {
        return var28;
    }
    return 0;
}
