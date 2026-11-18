#include <types.h>
#include <so/status/so_status_event_presenter.h>
#include <so/anim/so_anim_cmd_event_presenter.h>
#pragma force_active on

extern "C" char lbl_27_data_AA00[];
extern "C" char lbl_27_data_2D598[];
extern "C" void* __vt__21soStatusEventObserver[];
extern "C" void* __vt__22soAnimCmdEventObserver[];

class IAccSub {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual s16 s9();
};

struct Self {
    void* vt0;
    soStatusEventObserver status;
    soAnimCmdEventObserver anim;
    void* m1C;
};

extern "C" Self* fn_27_14FBD8(Self* self, u8* arg) {
    char* p = (char*)self;
    *(void**)p = lbl_27_data_AA00;

    s16 id = ((IAccSub*)(*(u8**)(*(u8**)(arg + 0xD8) + 0x80) + 8))->s9();
    soStatusEventObserver* status = (soStatusEventObserver*)(p + 4);
    status->m_manageID = -1;
    status->m_unitID = 4;
    status->m_sendID = -1;
    *(void**)status = __vt__21soStatusEventObserver;
    status->addObserver(id, -1);

    id = ((IAccSub*)(*(u8**)(*(u8**)(arg + 0xD8) + 0x80) + 8))->s9();
    soAnimCmdEventObserver* anim = (soAnimCmdEventObserver*)(p + 0x10);
    anim->m_manageID = -1;
    anim->m_unitID = 5;
    anim->m_sendID = -1;
    *(void**)anim = __vt__22soAnimCmdEventObserver;
    anim->addObserver(id, -1);

    *(void**)(p + 0x1C) = arg;
    *(char**)p = lbl_27_data_2D598;
    *(char**)(p + 4) = lbl_27_data_2D598 + 0x20;
    *(char**)(p + 0x10) = lbl_27_data_2D598 + 0x30;
    return self;
}
