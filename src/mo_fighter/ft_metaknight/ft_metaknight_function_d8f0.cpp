#pragma force_active on
#include <ft/ft_manager.h>

class FtSlotAccessor {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual unsigned int v11(int index);
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual unsigned int v44(int index);
};

extern "C" int fn_111_D8F0(int entryId, void* fighter) {
    Fighter* sub = g_ftManager->getSubFighter(entryId);
    unsigned int ownerId = -1;
    if (sub != 0) {
        ownerId = *(unsigned int*)((char*)sub + 0x28);
    }
    for (int i = 6; i < 12; i++) {
        FtSlotAccessor* acc = *(FtSlotAccessor**)((char*)*(void**)((char*)fighter + 0xd8) + 0x54);
        if (acc->v11(i) == 1) {
            acc = *(FtSlotAccessor**)((char*)*(void**)((char*)fighter + 0xd8) + 0x54);
            unsigned int taskId = acc->v44(i);
            if (ownerId == taskId) {
                return 0;
            }
            if (entryId == g_ftManager->getEntryIdFromTaskId(taskId, 0)) {
                return 1;
            }
        }
    }
    return 0;
}
