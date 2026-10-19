#pragma force_active on
extern "C" {
int fn_800B5854(void* p, int a, int b, int c, int d);
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void* self, void* p, char* s);
void fn_15_290C(char* self);
}

extern char lbl_15_data_C[];

class WatchObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v15(void* a);
};

void fn_15_290C(char* self) {
    fn_800B5854(*(void**)(self + 0x4c), 1, 1, 1, 0);
    *(int*)(self + 0x518) = 0x1e;
    WatchObj* obj = *(WatchObj**)(self + 0x194);
    char* other = *(char**)(self + 0x18c);
    obj->v15(*(void**)(other + 0x10));
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(obj, *(void**)(other + 0x10), lbl_15_data_C);
}
