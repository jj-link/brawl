#include <ec/ec_mgr.h>
#pragma force_active on

extern "C" {
void* fn_800607C8(ecMgr* mgr, u32 key);
void setMdlFrame__5ecMgrFUlfSc(ecMgr* mgr, u32 key, float frame, s8 arg);
}

extern u8* lbl_27_bss_7328;

class NullableVtbl {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6(int, int);
};

extern "C" void fn_27_2C9CDC(s32 arg0) {
    ecMgr* mgr = g_ecMgr;
    s32 var;

    if (arg0 >= 0) {
        setMdlFrame__5ecMgrFUlfSc(
            mgr, *(u32*)(lbl_27_bss_7328 + 0x1AF9C), (float)arg0, 2
        );

        NullableVtbl* model = (NullableVtbl*)fn_800607C8(
            mgr, *(u32*)(lbl_27_bss_7328 + 0x1AF9C)
        );
        if (model != NULL) {
            model->slot6(1, 0);
            model->slot6(6, 0);
            model->slot6(7, 0);
        }

        var = arg0 <= 2 ? 1 : 2;
    } else {
        NullableVtbl* model = (NullableVtbl*)fn_800607C8(
            mgr, *(u32*)(lbl_27_bss_7328 + 0x1AF9C)
        );
        if (model != NULL) {
            model->slot6(1, 1);
            model->slot6(6, 1);
            model->slot6(7, 1);
        }

        var = 2;
    }

    switch (var) {
    case 1:
    case 3:
        if (*(s32*)(lbl_27_bss_7328 + 0x1B000) != var) {
            mgr->setMdlAnmIdx(
                *(u32*)(lbl_27_bss_7328 + 0x1AF94), var, 1
            );
        }
        break;

    default:
    case 2: {
        s32 st = *(s32*)(lbl_27_bss_7328 + 0x1B000);
        if (st == 1 || st == 3) {
            mgr->setMdlAnmIdx(
                *(u32*)(lbl_27_bss_7328 + 0x1AF94), var, 1
            );
        }
        break;
    }
    }

    *(s32*)(lbl_27_bss_7328 + 0x1B000) = var;
}
