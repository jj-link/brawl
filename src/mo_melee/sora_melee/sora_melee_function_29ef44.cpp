#include <ft/ft_manager.h>
#include <ft/ft_owner.h>
#pragma force_active on

extern "C" int fn_27_10B21C(void*, int*);
extern "C" void fn_27_10CF94(void*, int, int, int, float);

extern const float lbl_27_rodata_46C8;

class StatusObject {
public:
    virtual ~StatusObject() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual int getStatus(int) = 0;
    virtual void release(int, int) = 0;
};

class TaskObject {
public:
    virtual ~TaskObject() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual void slot4() = 0;
    virtual void slot5() = 0;
    virtual void slot6() = 0;
    virtual void slot7() = 0;
    virtual int getTaskValue(void*) = 0;
};

extern "C" void fn_27_29EF44(void* unused, void* arg) {
    (void)unused;
    int entries[8];

    void* p60 = *(void**)((char*)arg + 0x60);
    void* pD8 = *(void**)((char*)p60 + 0xD8);
    StatusObject* statusObject = *(StatusObject**)((char*)pD8 + 0x64);

    int status = statusObject->getStatus(0x10000000);
    if (status >= 0) {
        int count = fn_27_10B21C(g_ftManager, entries);
        int* entryPtr;

        int taskValue =
            (*(TaskObject**)((char*)*(void**)((char*)*(void**)((char*)arg + 0x60) + 0xD8) + 0x18))
                ->getTaskValue(*(void**)((char*)arg + 0x60));

        switch (status) {
        case 2: {
            entryPtr = entries;
            int i = 0;
            while (i < count) {
                int entryId = *entryPtr;
                if (g_ftManager->isValidEntryId(entryId) &&
                    entryId != g_ftManager->getEntryIdFromTaskId(taskValue, 0)) {
                    g_ftManager->getOwner(entryId)->setSlipMul(lbl_27_rodata_46C8);
                    g_ftManager->getOwner(entryId)->setSlipInterval(true);
                }
                ++entryPtr;
                ++i;
            }
            break;
        }

        case 4:
            if ((unsigned)(taskValue + 0x10000) != 0xFFFFU) {
                int entryId = g_ftManager->getEntryIdFromTaskId(taskValue, 0);
                if (g_ftManager->isValidEntryId(entryId)) {
                    fn_27_10CF94(g_ftManager, entryId, 0, 1, lbl_27_rodata_46C8);
                }
            }
            break;
        }

        statusObject->release(-1, 0x10000000);
    }
}
