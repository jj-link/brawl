#include <revolution/types.h>
#pragma force_active on

typedef struct DwcFriendsMatchObj {
    s32 unk00;
    unsigned char pad04[0x1C - 0x04];
    unsigned char unk1C[0x24 - 0x1C];
    s32 unk24;
    s32 unk28;
    unsigned char pad2C[0xA0 - 0x2C];
    s32 unkA0;
    unsigned char padA4[0x370 - 0xA4];
    void *unk370;
    unsigned char pad374[0x375 - 0x374];
    unsigned char unk375;
    unsigned char pad376[0x38C - 0x376];
    unsigned char unk38C;
} DwcFriendsMatchObj;

extern DwcFriendsMatchObj *lbl_805A0F88;
extern char lbl_80489EAC[];

extern s32 fn_80335238(void);
extern void fn_80335638(s32, const char *, ...);
extern s32 fn_8035E1A8(void);
extern void fn_80367C28(void *, s32, s32, s32);
extern s32 fn_8033AEEC(void);
extern void fn_80367CB0(void *, s32, void (*)(void), s32);
extern void fn_8033B45C(void);
extern void fn_8033B8CC(void);
extern void fn_8033703C(void);
extern void fn_80336FAC(void);
extern void fn_803370C0(void);
extern s32 fn_80338754(void);
extern void fn_80338938(s32, s32);
extern void fn_803387A0(void);
extern void fn_80336BC0(void);
extern void fn_8033DD60(s32);
extern void fn_8034E790(void);
extern void fn_803791BC(void *);

void DWC_ProcessFriendsMatch(void) {
    s32 state;
    DwcFriendsMatchObj *obj;
    const DwcFriendsMatchObj *cobj;

    if (lbl_805A0F88 != 0 && lbl_805A0F88->unk24 != 0) {
        switch (fn_80335238()) {
        case 0:
            state = lbl_805A0F88->unk24;
            switch (state) {
            case 1:
                switch (fn_8035E1A8()) {
                case 1:
                    fn_80335638(0x10, lbl_80489EAC);
                    fn_80367C28(lbl_805A0F88->unk1C, lbl_805A0F88->unkA0, 0x10, 0xB);
                    if (fn_8033AEEC() != 0) {
                        return;
                    }
                    fn_80367CB0(lbl_805A0F88->unk1C, 0, fn_8033B45C, 0);
                    if (fn_8033AEEC() != 0) {
                        return;
                    }
                    fn_80367CB0(lbl_805A0F88->unk1C, 3, fn_8033B8CC, 0);
                    if (fn_8033AEEC() != 0) {
                        return;
                    }
                    fn_80367CB0(lbl_805A0F88->unk1C, 7, fn_8033703C, 0);
                    if (fn_8033AEEC() != 0) {
                        return;
                    }
                    fn_80367CB0(lbl_805A0F88->unk1C, 1, fn_80336FAC, 0);
                    if (fn_8033AEEC() != 0) {
                        return;
                    }
                    fn_80367CB0(lbl_805A0F88->unk1C, 2, fn_803370C0, 0);
                    if (fn_8033AEEC() != 0) {
                        return;
                    }
                    lbl_805A0F88->unk28 = lbl_805A0F88->unk24;
                    lbl_805A0F88->unk24 = 2;
                    if (fn_80338754() == 0) {
                        fn_80338938(2, -0x4E84);
                    }
                    break;
                case 2:
                    fn_80338938(3, -0x4E8E);
                    return;
                case 3:
                    fn_80338938(4, -0x4E85);
                    return;
                }
                break;
            case 2:
                fn_803387A0();
                break;
            case 3:
            case 4:
                fn_80336BC0();
                fn_8033DD60(0);
                break;
            case 5:
                fn_8033DD60(1);
                fn_80336BC0();
                break;
            case 6:
                fn_8034E790();
                fn_80336BC0();
                obj = lbl_805A0F88;
                cobj = lbl_805A0F88;
                if (obj->unk375 == 2 || cobj->unk375 == 3) {
                    fn_8033DD60(1);
                } else if (obj->unk00 != 0) {
                    fn_8033DD60(0);
                }
                break;
            }

            if (lbl_805A0F88->unk38C == 1) {
                if (lbl_805A0F88->unk370 != 0) {
                    fn_803791BC(lbl_805A0F88->unk370);
                    lbl_805A0F88->unk370 = 0;
                }
                lbl_805A0F88->unk38C = 0;
            }
            break;
        default:
            break;
        }
    }
}
