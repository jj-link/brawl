#include <types.h>
#pragma force_active on

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*, unsigned long, unsigned long);
extern const char lbl_27_data_7A0C0[];
extern const char __RTTI__16soResourceModule[];
extern const float lbl_27_rodata_5FF8;

struct gfTask_base { char pad[0x3c]; };
class gfTask : public gfTask_base {
public:
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
    virtual int slot40();
};

extern "C" float fn_27_2C0924(void* p0, void* acc, int id, u32 arg) {
    if (id <= 0xf9f) {
        return getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, id, arg);
    }
    void* enumStart = *(void**)((char*)acc + 0xD8);
    void* rm = *(void**)enumStart;
    void* castResult = __dynamic_cast(rm, 8, lbl_27_data_7A0C0, __RTTI__16soResourceModule, 1);
    void* inner = *(void**)((char*)castResult + 0x34);
    if (*(void**)((char*)inner + 0xEC) != 0) {
        gfTask* obj = (gfTask*)*(void**)((char*)acc + 0x8);
        int frame = obj->slot40();
        void* arr = *(void**)((char*)inner + 0xEC);
        int idx = (int)arg + (id - 0xFA0 - frame * 0x32);
        if (idx >= 0) {
            unsigned count = *(unsigned*)((char*)arr + 0x14);
            if ((unsigned)idx < count) {
                float* data = *(float**)((char*)arr + 0x10);
                return data[idx];
            }
        }
    }
    return lbl_27_rodata_5FF8;
}
