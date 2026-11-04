#include <gr/gr_gimmick.h>
#pragma force_active on

extern int lbl_27_data_5677C;
extern int lbl_27_data_56780;

class AttachedEffect {
public:
    virtual void v0();
    virtual void v1(float frame);
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual int v11();
    int field;
};

extern "C" void fn_27_26AF10(grGimmick* self, float frame) {
    char* p = reinterpret_cast<char*>(self);
    int hasB = 0;
    int allOk = 1;
    for (int i = 0; i < 10; i++) {
        if (*reinterpret_cast<AttachedEffect**>(p + 0xFC) != 0) {
            (*reinterpret_cast<AttachedEffect**>(p + 0xFC))->v1(frame);
            if ((*reinterpret_cast<AttachedEffect**>(p + 0xFC))->v11() != 0) {
                (*reinterpret_cast<AttachedEffect**>(p + 0xFC))->field = lbl_27_data_5677C;
            }
        }
        if (*reinterpret_cast<AttachedEffect**>(p + 0x124) != 0) {
            hasB = 1;
            (*reinterpret_cast<AttachedEffect**>(p + 0x124))->v1(frame);
            if ((*reinterpret_cast<AttachedEffect**>(p + 0x124))->v11() != 0) {
                (*reinterpret_cast<AttachedEffect**>(p + 0x124))->field = lbl_27_data_56780;
            } else {
                allOk = 0;
            }
        }
        p += 4;
    }
    if (hasB != 0 && allOk != 0) {
        self->Ground::setVisibilityAttachedEffect(0);
    }
}
