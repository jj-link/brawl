#include <types.h>
#include <so/event/so_event_system.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_2A918[];
extern char lbl_27_data_2A9A8[];
extern char lbl_27_data_21018[];
extern char lbl_27_data_2A924[];
extern char lbl_27_data_2A930[];
extern char lbl_27_data_2103C[];
extern char lbl_27_data_7310[];
extern char lbl_27_data_21030[];
extern char lbl_27_data_21024[];
extern char lbl_27_data_14FE8[];
extern char lbl_27_data_5B3C[];
extern char lbl_27_data_731C[];
extern char lbl_27_data_5B30[];
extern char lbl_27_data_1180[];
void __dl__FPv(void*);
void fn_27_3994(void*, s32);
}

struct ObsEntry {
    void* vptr;
    s16 manageID;
    s16 unitID;
    s16 sendID;
    char pad[2];
};

struct Obj {
    char pad0[0x64];
    ObsEntry e[14];
};

#define SO_OBS_RELEASE(ent, vt)                                                          \
    if (&(ent)) {                                                                        \
        if (&(ent)) {                                                                    \
            s16 mgr = (ent).manageID;                                                    \
            (ent).vptr = vt;                                                             \
            if (soEventSystem::getInstance()->getInstanceManager().isContain(mgr) == 1) { \
                soEventSystem::getInstance()->getManager((ent).manageID)                 \
                    ->eraseObserver((ent).unitID, (ent).sendID);                         \
            }                                                                            \
            (ent).sendID = -1;                                                           \
            (ent).manageID = -1;                                                         \
        }                                                                                \
    }

extern "C" Obj* fn_27_125E20(Obj* self, s32 flag) {
    if (self) {
        SO_OBS_RELEASE(self->e[13], lbl_27_data_2A918);
        SO_OBS_RELEASE(self->e[12], lbl_27_data_2A9A8);
        SO_OBS_RELEASE(self->e[11], lbl_27_data_21018);
        SO_OBS_RELEASE(self->e[10], lbl_27_data_2A924);
        SO_OBS_RELEASE(self->e[9], lbl_27_data_2A930);
        SO_OBS_RELEASE(self->e[8], lbl_27_data_2103C);
        SO_OBS_RELEASE(self->e[7], lbl_27_data_7310);
        SO_OBS_RELEASE(self->e[6], lbl_27_data_21030);
        SO_OBS_RELEASE(self->e[5], lbl_27_data_21024);
        SO_OBS_RELEASE(self->e[4], lbl_27_data_14FE8);
        SO_OBS_RELEASE(self->e[3], lbl_27_data_5B3C);
        SO_OBS_RELEASE(self->e[2], lbl_27_data_731C);
        SO_OBS_RELEASE(self->e[1], lbl_27_data_5B30);
        SO_OBS_RELEASE(self->e[0], lbl_27_data_1180);
        fn_27_3994(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
