#include <types.h>
#pragma force_active on
class ftManager;
extern ftManager* g_ftManager;
extern "C" void* g_IfMngr;
extern "C" int fn_27_10AAC4(ftManager*, int);
extern "C" void fn_800E1ED8(void*, int, int);
class ftOutsideEventObserver {
public:
    virtual void addObserver();
    virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4();
    virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8();
    virtual void slot9(); virtual void slot10(); virtual void notifyEventChangeAppear();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
    virtual void notifyEventStartFinal(); virtual void notifyEventEndFinal();
    virtual void slot22(); virtual void slot23(); virtual void slot24(); virtual void slot25();
    virtual void slot26(); virtual void slot27(); virtual void slot28(); virtual void slot29();
    virtual void slot30(); virtual void slot31(); virtual void slot32(); virtual void slot33();
    virtual void slot34(); virtual void slot35(); virtual void slot36(); virtual void slot37();
    virtual void slot38(); virtual void slot39(); virtual void slot40(); virtual void slot41();
    virtual void slot42(); virtual int slot43();
    char pad[8];
    u8* base;
};
extern "C" void fn_27_27E2EC(ftOutsideEventObserver* self, int id, int index, int unused, int kind) {
    if (self->slot43()) {
        int value;
        switch (fn_27_10AAC4(g_ftManager, id)) {
        case 29: case 31: case 33:
            switch (kind) {
            case 29: value = 29; break;
            case 31: value = 33; break;
            case 30: value = 31; break;
            }
            break;
        case 3: case 4:
            switch (kind) {
            case 3: value = 3; break;
            case 24: value = 4; break;
            }
            break;
        case 14: case 15:
            switch (kind) {
            case 13: value = 14; break;
            case 14: value = 15; break;
            }
            break;
        case 12: case 44:
            switch (kind) {
            case 11: value = 12; break;
            case 48: value = 44; break;
            }
            break;
        case 23: case 45:
            switch (kind) {
            case 21: value = 23; break;
            case 49: value = 45; break;
            }
            break;
        default: return;
        }
        u8* mgr = (u8*)g_IfMngr;
        fn_800E1ED8(*(void**)(mgr + 0x4c + (mgr + (self->base + index * 0x5c)[0x9a])[0x68] * 4), 0, value);
    }
}