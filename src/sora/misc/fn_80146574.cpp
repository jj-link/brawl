#include <nt/nt_offline.h>
#include <nt/nt_report.h>
#include <mu/wifi/mu_wifi_interface.h>
#pragma force_active on

class Class_8042B6D0 {
public:
    virtual void fn_8004805C(int);
};

struct NetworkWork : NtBase {
    u8 pad8[0x33F4 - 8];
    u8 unk33F4;
};

struct NetworkContext {
    u8 pad0[0x30];
    NetworkWork* work30;
    NtBase* work34;
    NtBase* work38;
    NtReport* work3C;
};

extern char lbl_8045F244[];
extern char lbl_8045F260[];

extern "C" void fn_80149EF8(NetworkWork*);
extern "C" void fn_80143C44(NtBase*);
extern "C" void fn_8013EFCC(NtBase*);

extern "C" void fn_80146574(NetworkContext* self) {
    if (gUnk805a03d8 == 0) {
        netReport(lbl_8045F244);
        return;
    }
    netReport(lbl_8045F260);
    ntFriendInfo* info = ntFriendInfo::getInstance();
    (*(u8**)info)[0x577] = 2;
    self->work30->unk33F4 = 1;
    fn_80149EF8(self->work30);
    if (self->work30 != 0) {
        reinterpret_cast<Class_8042B6D0*>(self->work30)->fn_8004805C(1);
    }
    self->work30 = 0;
    fn_80143C44(self->work38);
    if (self->work38 != 0) {
        reinterpret_cast<Class_8042B6D0*>(self->work38)->fn_8004805C(1);
    }
    self->work38 = 0;
    fn_8013EFCC(self->work34);
    if (self->work34 != 0) {
        reinterpret_cast<Class_8042B6D0*>(self->work34)->fn_8004805C(1);
    }
    self->work34 = 0;
    self->work3C->destroyWork();
    if (self->work3C != 0) {
        reinterpret_cast<Class_8042B6D0*>(self->work3C)->fn_8004805C(1);
    }
    self->work3C = 0;
    gUnk805a03d8 = 0;
}
