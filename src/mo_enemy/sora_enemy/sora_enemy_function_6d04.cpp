#include <types.h>
#include <em/em_manager.h>
#pragma force_active on

extern "C" u32 fn_41_CB10(u32 a, u32 param1, u32 param2);

class soNullableSlots {
public:
    virtual void isNull();
    virtual void slot1();
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
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual u32 slot17(u32 flag);
    virtual void slot18(u32 flag);
};

extern "C" s32 fn_41_6D04(u32 a, u32 b) {
    if (fn_41_CB10((u32)emManager::getInstance(), a, b) == 1) {
        Enemy* enemy = emManager::getInstance()->getEnemyPtrFromId(b);
        if (enemy == nullptr) {
            return 1;
        }
        void* sub = *(void**)((u8*)enemy + 0x1b4);
        soNullableSlots* obj = *(soNullableSlots**)((u8*)sub + 0x64);
        if (obj->slot17(0x12000000) == 1) {
            return 1;
        }
        sub = *(void**)((u8*)enemy + 0x1b4);
        obj = *(soNullableSlots**)((u8*)sub + 0x64);
        obj->slot18(0x22000003);
        sub = *(void**)((u8*)enemy + 0x1b4);
        obj = *(soNullableSlots**)((u8*)sub + 0x64);
        obj->slot18(0x12000000);
    }
    return 1;
}
