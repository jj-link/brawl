#include <types.h>
#pragma force_active on

extern "C" void OSReport(const char* format, ...);
extern "C" void fn_27_28F6D4(void* self, int x, int y, float a, float b);
extern "C" int getParam__8BaseItemFQ215itValueAccesser8ParamInt(void* self, int id);

extern const char lbl_27_data_17528[];
extern const float lbl_27_rodata_E68;

struct Result {
    s32 kind;
    void* item;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual Result* slot1(int);
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual int slot14(int);
};

class Owner {
public:
    virtual void slot0();
    virtual Result* slot1(int);
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual int slot14(int);
    char pad[0x34];
    Object_vptr_0* child;
};

extern "C" void fn_27_BAB24(Owner* self, int arg1, int arg2, float farg0)
{
    if (self->slot14(arg2) != 0) {
        int param;
        switch (self->child->slot1(arg2)->kind) {
        case 4:
            param = getParam__8BaseItemFQ215itValueAccesser8ParamInt(self->child->slot1(arg2)->item, 0x5E88);
            break;
        default:
            OSReport(lbl_27_data_17528);
            return;
        }
        fn_27_28F6D4(self->child->slot1(arg2)->item, param, arg1, farg0, lbl_27_rodata_E68);
    }
}
