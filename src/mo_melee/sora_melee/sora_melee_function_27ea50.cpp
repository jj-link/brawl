#include <types.h>
#pragma force_active on

class ftManager;
extern ftManager* g_ftManager;
extern "C" void* g_IfMngr;
extern "C" int getPlayerNo__9ftManagerFi(ftManager* self, int playerNo);
extern "C" void fn_800DD0CC(void* mgr, u8 a, u8 b);

class ftOutsideEventObserver {
public:
    virtual void addObserver();                       // slot 0, 0x8
    virtual void notifyEventOnDamage();               // slot 1
    virtual void notifyEventSetDamage();              // slot 2
    virtual void notifyEventRecover();                // slot 3
    virtual void notifyEventOutsideDeadArea();        // slot 4
    virtual void notifyEventAppeal();                 // slot 5
    virtual void notifyEventDead();                   // slot 6
    virtual void notifyEventBeat();                   // slot 7
    virtual void notifyEventSuicide();                // slot 8
    virtual void notifyEventChangeStart();            // slot 9
    virtual void notifyEventChangeEnd();              // slot 10
    virtual void notifyEventChangeAppear();           // slot 11
    virtual void notifyEventAddDragoonParts();        // slot 12
    virtual void notifyEventCompDragoonParts();       // slot 13
    virtual void notifyEventRemoveDragoonParts();     // slot 14
    virtual void notifyEventResetDragoonParts();      // slot 15
    virtual void notifyEventReEntryRequestFighter();  // slot 16
    virtual void notifyEventSetCursor();              // slot 17
    virtual void notifyEventSetNameCursor();          // slot 18
    virtual void notifyEventSetLoupe();               // slot 19
    virtual void notifyEventStartFinal();             // slot 20
    virtual void notifyEventEndFinal();               // slot 21
    virtual void notifyEventRemoveEntry();            // slot 22
    virtual void notifyEventFinalSlow();              // slot 23
    virtual void notifyEventFinalSlowCancel();        // slot 24
    virtual void notifyEventFinalStop();              // slot 25
    virtual void notifyEventFinalStopCancel();        // slot 26
    virtual void notifyEventEntryEnd();               // slot 27
    virtual void notifyEventResultEnd();              // slot 28
    virtual void notifyEventGetItem();                // slot 29
    virtual void notifyEventSucceedHit();             // slot 30
    virtual void notifyEventResultWin();              // slot 31
    virtual void notifyEventYoshiEggStart();          // slot 32
    virtual void notifyEventYoshiEggEnd();            // slot 33
    virtual void notifyEventOnInput();                // slot 34
    virtual void notifyEventPikminMakeBloomAll();     // slot 35
    virtual void notifyEventKirbyCopySetup();         // slot 36
    virtual void notifyEventKirbyCopyCancel();        // slot 37
    virtual void notifyEventKnockout();               // slot 38
    virtual void notifyEventHeartSwapStart();         // slot 39, 0xa4
    virtual void notifyEventHeartSwapEnd();           // slot 40
    virtual void slot41();                            // slot 41
    virtual void slot42();                            // slot 42
    virtual int slot43();                             // slot 43, 0xb4

    char _4[8];
    u8* m_base;  // offset 0xc
};

extern "C" void fn_27_27EA50(ftOutsideEventObserver* self, int entryId1, int entryId2) {
    if (self->slot43() != 0) {
        int idx1 = getPlayerNo__9ftManagerFi(g_ftManager, entryId1);
        u8 a = (self->m_base + idx1 * 0x5C)[0x9A];
        int idx2 = getPlayerNo__9ftManagerFi(g_ftManager, entryId2);
        u8 b = (self->m_base + idx2 * 0x5C)[0x9A];
        fn_800DD0CC(g_IfMngr, a, b);
    }
}
