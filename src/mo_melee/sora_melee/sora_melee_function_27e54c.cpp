#include <types.h>
#pragma force_active on

class ftManager {
public:
    int getPlayerNo(int entryId);
};

extern ftManager* g_ftManager;

struct SubPad {
    u8 pad[0x3c];
};

class SubObj : public SubPad {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf32();
    virtual void vf33(u8, s32);
};

class SelfT {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual bool vf45();
    u8 m_pad4[8];
    u8* m_entries;
    u8 m_pad10[0x1c];
    SubObj* m_sub;
    u8 m_pad30[4];
    u8 m_flags;
};

extern "C" void fn_27_27E54C(SelfT* self, s32 entryId, s32 arg2) {
    if (self->vf45()) {
        if ((self->m_flags >> 7) & 1) {
            if (self->m_sub != 0) {
                int playerNo = g_ftManager->getPlayerNo(entryId);
                u8* entry = self->m_entries + playerNo * 0x5c;
                if (!((entry[0xb3] >> 2) & 1)) {
                    self->m_sub->vf33(entry[0x9a], arg2);
                }
            }
        }
    }
}
