#pragma force_active on

struct FtPikminDispatch {
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
};

struct FtPikminLeaf {
    char pad[0x64];
    FtPikminDispatch* m_dispatch;
};

struct FtPikminMid {
    char pad[0xd8];
    FtPikminLeaf* m_leaf;
};

struct FtPikminRoot {
    char pad[0x60];
    FtPikminMid* m_mid;
};

extern "C" void fn_113_18EE4(FtPikminRoot* root) {
    root->m_mid->m_leaf->m_dispatch->vf13();
}
