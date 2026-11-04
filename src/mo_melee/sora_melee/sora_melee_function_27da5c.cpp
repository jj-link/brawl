#include <ft/ft_manager.h>
#include <if/if_mngr.h>
#pragma force_active on

class BeatTask : public gfTask {
public:
    virtual void fn_27_248C88();
    virtual void fn_27_248C80();
    virtual void fn_27_248C78();
    virtual int fn_27_248C70();
    virtual void fn_27_23FEB4();
    virtual void fn_27_256954();
    virtual void fn_27_255D04();
    virtual void fn_27_255D78();
    virtual void fn_27_248C6C();
    virtual void fn_27_247EE8();
    virtual void fn_27_247EEC();
    virtual void fn_27_248010();
    virtual void fn_27_248084();
    virtual void fn_27_247EF4(int, int);
};

struct BeatPlayer {
    unsigned char index;
    char pad01[8];
    unsigned char team;
    char pad0A[0x52];
};

struct BeatByte { unsigned char value; };

struct BeatData {
    char pad00[0xB];
    unsigned char flags;
    char pad0C[7];
    unsigned char teams;
    char pad14[0x86];
    BeatPlayer players[1];
};

class BeatObserver : public ftOutsideEventObserver {
public:
    virtual void fn_27_27D1CC();
    virtual void fn_27_27D28C();
    virtual int fn_27_27CED8();
    BeatData* data;
    char pad10[0x20];
    BeatTask* task;
    unsigned char flags;
};

extern "C" void fn_800E3388(void*, int);
extern "C" void* fn_80158638();
extern "C" void fn_80158A5C(void*, int, int);

extern "C" void fn_27_27DA5C(BeatObserver* self, int entry1, int entry2) {
    if (self->fn_27_27CED8() && ((self->flags >> 5) & 1) &&
        (!self->task || !self->task->fn_27_248C70())) {
        int player1 = g_ftManager->getPlayerNo(entry1);
        int player2 = g_ftManager->getPlayerNo(entry2);
        if (self->task) {
            self->task->fn_27_247EF4(player1, player2);
        } else {
            BeatData* data = self->data;
            if (((data->flags >> 2) & 1) && g_IfMngr) {
                if (data->teams == 1 && ((BeatByte*)((char*)data + 0xA3))[player1 * 0x5C].value == ((BeatByte*)((char*)data + 0xA3))[player2 * 0x5C].value) {
                    fn_800E3388(g_IfMngr->m_ifPlayers[*((unsigned char*)data + player1 * 0x5C + 0x9A)], -1);
                    fn_800E3388(g_IfMngr->m_ifPlayers[*((unsigned char*)self->data + player2 * 0x5C + 0x9A)], -1);
                } else {
                    fn_800E3388(g_IfMngr->m_ifPlayers[*((unsigned char*)data + player1 * 0x5C + 0x9A)], 1);
                    fn_800E3388(g_IfMngr->m_ifPlayers[*((unsigned char*)self->data + player2 * 0x5C + 0x9A)], -1);
                }
            }
        }
        void* object = fn_80158638();
        if (object) {
            fn_80158A5C(object, player1, player2);
        }
    }
}
