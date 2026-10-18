#pragma force_active on
extern "C" {

extern void* g_ftManager;
int fn_27_10A4B0(void*, int);
void* getFighter__9ftManagerFii(void*, int, int);

class VObj {
public:
    virtual int v0(int);
    virtual int v1(int);
    virtual int v2(int);
    virtual int v3(int);
    virtual int v4(int);
    virtual int v5(int);
    virtual int v6(int);
    virtual int v7(int);
    virtual int v8(int);
    virtual int v9(int);
    virtual int v10(int);
    virtual int v11(int);
    virtual int v12(int);
    virtual int v13(int);
    virtual int v14(int);
    virtual int v15(int);
    virtual int v16(int);
    virtual int v17(int);
};

void* fn_105_B09C(void* obj) {
    void* mgr = g_ftManager;
    int result = fn_27_10A4B0(mgr, *(int*)((char*)obj + 0x10c));
    if ((unsigned)(result & 0xFF) > 1) {
        int idx = 1;
        void* p0 = *(void**)((char*)obj + 0x60);
        void* p1 = *(void**)((char*)p0 + 0xd8);
        VObj* p2 = *(VObj**)((char*)p1 + 0x64);
        int ret = p2->v17(0x1200003E);
        if (ret != 0)
            idx = 0;
        return getFighter__9ftManagerFii(mgr, *(int*)((char*)obj + 0x10c), idx);
    }
    return 0;
}

}
