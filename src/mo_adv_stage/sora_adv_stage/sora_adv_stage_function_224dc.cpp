#include <types.h>
#include <st/st_trigger.h>
#pragma force_active on

struct GroundBase { char pad[0x3C]; };

class Ground : public GroundBase {
public:
#define S(n) virtual void s##n();
S(0)S(1)S(2)S(3)S(4)S(5)S(6)S(7)S(8)S(9)
S(10)S(11)S(12)S(13)S(14)S(15)S(16)S(17)S(18)S(19)
S(20)S(21)S(22)S(23)S(24)S(25)S(26)S(27)S(28)S(29)
S(30)S(31)S(32)S(33)S(34)S(35)S(36)S(37)S(38)S(39)
S(40)S(41)S(42)S(43)S(44)S(45)S(46)S(47)S(48)S(49)
S(50)S(51)S(52)S(53)S(54)S(55)S(56)S(57)S(58)S(59)
#undef S
    virtual void setValid(u32 flag);
};

struct Node {
    u32 unk0;
    Node* next;
    Ground* obj;
};

struct TriggerHolder {
    char pad[0x48];
    stTriggerData data;
};

class Owner {
public:
    char pad0[0x154];
    Node* head;
    char pad1[4];
    Node* cur;
    u32 count;
    TriggerHolder* holder;
};

extern "C" void fn_40_224DC(Owner* self) {
    if (self->holder->data.m_triggerId != 0) {
        if (g_stTriggerMng->getTriggerFlag(&self->holder->data, true) == 1) {
            u32 count = self->count;
            self->cur = self->head;
            for (u32 i = 0; i < count; i++) {
                self->cur->obj->setValid(0);
                self->cur = self->cur->next;
            }
        }
    }
}
