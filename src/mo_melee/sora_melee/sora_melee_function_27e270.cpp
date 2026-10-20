#pragma force_active on
class ftManager {
public:
    int getPlayerNo(int);
};

class fn27Base {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
    virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42();
    virtual bool isTarget();
};

extern "C" {
    extern ftManager* g_ftManager;
    extern void* g_IfMngr;
    void fn_800DCD74(void*, unsigned char);
}

extern "C" void fn_27_27E270(fn27Base* self, int playerNo) {
    if (self->isTarget()) {
        int idx = g_ftManager->getPlayerNo(playerNo);
        unsigned char b = *(unsigned char*)(*(char**)((char*)self + 0xc) + idx * 0x5c + 0x9a);
        fn_800DCD74(g_IfMngr, b);
    }
}
