#include <types.h>
#include <revolution/SI/SIHardware.h>
#pragma force_active on

typedef struct SIMain {
    s32 chan;
    u32 poll;
    u32 inSize;
    void* inAddr;
    void* callback;
} SIMain;

extern s64 fn_801E1B54(void);
extern SIMain lbl_80474E98;
extern u32 lbl_80474EB0[];
extern s64 lbl_804DE3B0[];
extern s64 lbl_804DE3D0[];

static void SIClearTCInterrupt(void)
{
    u32 csr = SI_HW_REGS[SI_SICOMSCR];

    csr |= SI_SICOMCSR_TCINT;
    csr &= ~SI_SICOMCSR_TSTART;

    SI_HW_REGS[SI_SICOMSCR] = csr;
}

u32 fn_801E5F9C(void)
{
    u32 i;
    u32 sr;
    u8* dst;
    u32 size;
    u32 imm;

    sr = SI_HW_REGS[SI_SISR];
    SIClearTCInterrupt();

    if (lbl_80474E98.chan != -1) {
        lbl_804DE3B0[lbl_80474E98.chan] = fn_801E1B54();

        dst = (u8*)lbl_80474E98.inAddr;

        size = lbl_80474E98.inSize / sizeof(u32);
        for (i = 0; i < size; dst += sizeof(u32), i++) {
            *(u32*)dst = SI_HW_REGS[SI_RAM_BASE + i];
        }

        size = lbl_80474E98.inSize % sizeof(u32);
        if (size > 0) {
            imm = SI_HW_REGS[SI_RAM_BASE + i];

            for (i = 0; i < size; dst++, i++) {
                *dst = imm >> (3 - i) * 8;
            }
        }

        if (SI_HW_REGS[SI_SICOMSCR] & SI_SICOMCSR_COMERR) {
            sr >>= (3 - lbl_80474E98.chan) * 8;
            sr &= (SI_UNRUN | SI_OVRUN | SI_COLL | SI_NOREP);

            if ((sr & SI_NOREP) && (lbl_80474EB0[lbl_80474E98.chan] & 0x80) == 0) {
                lbl_80474EB0[lbl_80474E98.chan] = 8;
            }

            if (sr == 0) {
                sr = SI_COLL;
            }
        } else {
            lbl_804DE3D0[lbl_80474E98.chan] = fn_801E1B54();
            sr = 0;
        }

        lbl_80474E98.chan = -1;
    }

    return sr;
}
