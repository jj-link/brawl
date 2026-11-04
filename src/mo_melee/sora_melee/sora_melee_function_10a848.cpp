#include <ft/ft_entry_manager.h>
#include <so/so_external_value_accesser.h>
#pragma force_active on

extern "C" s32 fn_27_1190D0(ftEntryManager*);

struct TaskBase { char pad[0x3c]; };
struct Task : TaskBase {
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void processCamera();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void renderOpa(); virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void init(); virtual void slot22(); virtual void slot23();
    virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
    virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
    virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35();
    virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual void fn_27_248088();
    virtual void slot40(); virtual s32 slot41();
};

extern "C" s32 fn_27_10A848(u8* self, u32 id, s32 index) {
    if (fn_27_1190D0(*(ftEntryManager**)(self + 0x154)) == 0) {
        index = 0;
    } else if (index != -1) {
        char* entry = (char*)(*(ftEntryManager**)(self + 0x154))->getEntity(id);
        index = *(s32*)(entry + (index << 3) + 0x34);
    } else {
        char* entry = (char*)(*(ftEntryManager**)(self + 0x154))->getEntity(id);
        u8 n = *(u8*)(entry + 0xa);
        index = *(s32*)(entry + (n << 3) + 0x34);
    }
    s32 result = 0;
    if (index != 0 && ((Task*)index)->slot41() != 0 && soExternalValueAccesser::getSituationKind((StageObject*)index) != 5) {
        result = 1;
    }
    return result;
}