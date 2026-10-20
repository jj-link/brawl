#pragma force_active on
struct FtOwnerPad {
    int a, b, c;
};

class FtOwner : public FtOwnerPad {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

extern "C" {
extern void* g_ftManager;
int getEntryId__9ftManagerFi(void*);
FtOwner* getOwner__9ftManagerFi(void*, int);
}

extern "C" void fn_40_5CD8() {
    int id = getEntryId__9ftManagerFi(g_ftManager);
    if (id != -1) {
        FtOwner* owner = getOwner__9ftManagerFi(g_ftManager, id);
        owner->vf3();
        owner->vf4();
    }
}
