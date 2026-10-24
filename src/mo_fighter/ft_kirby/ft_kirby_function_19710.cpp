#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
int fn_96_19658(void* owner, void* accesser);
int fn_96_1992C(void* owner);
int fn_96_19E88(void* owner);
void fn_96_19A38(void* owner, void* accesser);
void fn_96_19FF8(void* owner, void* accesser);
}

// Views of the target object that only reproduce the vtable layout used here.
// Declared index i sits at vtable byte offset (i + 2) * 4.
class ftKirbyFlagView {
public:
    virtual void s00();
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual int hasFlag(unsigned long index);   // +0x4C
    virtual void onFlag(unsigned long index);   // +0x50
    virtual void offFlag(unsigned long index);  // +0x54
};

static ftKirbyFlagView* getFlagView(void* accesser) {
    char* module = *reinterpret_cast<char**>(static_cast<char*>(accesser) + 0xD8);
    return *reinterpret_cast<ftKirbyFlagView**>(module + 0x64);
}

extern "C" void fn_96_19710(void* owner, void* accesser) {
    if (getFlagView(accesser)->hasFlag(0x22000020) != 0) {
        getFlagView(accesser)->offFlag(0x2200001F);
    } else {
        int r27 = fn_96_19658(owner, accesser);
        int r28 = fn_96_1992C(owner);
        int r29 = fn_96_19E88(owner);
        if (r27 != 0) {
            getFlagView(accesser)->onFlag(0x2200001F);
            if (getFlagView(accesser)->hasFlag(0x2200001D) != 0) {
                if (r29 != 0) {
                    getFlagView(accesser)->onFlag(0x2200001E);
                    getFlagView(accesser)->offFlag(0x2200001D);
                }
            } else {
                if (getFlagView(accesser)->hasFlag(0x2200001E) != 0) {
                    if (r28 != 0) {
                        getFlagView(accesser)->onFlag(0x2200001D);
                        getFlagView(accesser)->offFlag(0x2200001E);
                    }
                } else if (r28 != 0) {
                    getFlagView(accesser)->onFlag(0x2200001D);
                } else if (r29 != 0) {
                    getFlagView(accesser)->onFlag(0x2200001E);
                }
            }
        } else {
            getFlagView(accesser)->offFlag(0x2200001F);
        }
    }
    fn_96_19A38(owner, accesser);
    fn_96_19FF8(owner, accesser);
}
