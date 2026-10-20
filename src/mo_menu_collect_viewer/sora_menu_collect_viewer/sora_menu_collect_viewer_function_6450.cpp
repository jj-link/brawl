#pragma force_active on

struct MuObject;

struct VtBase {
    char _[0x3c];
};

class Derived : public VtBase {
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
    virtual void v44(void*);
};

struct Sub {
    char pad[0x10c];
    MuObject* obj;
    char pad2[0x190 - 0x110];
    void* field190;
};

extern "C" {
void setFrameNode__8MuObjectFf(MuObject*, float);
void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);
extern void* g_sndSystem;
extern const float lbl_6_rodata_1C8;
}

extern "C" void fn_6_6450(Derived* self) {
    setFrameNode__8MuObjectFf(((Sub*)*(void**)((char*)self + 0x1ac))->obj, lbl_6_rodata_1C8);
    self->v44(*(void**)((char*)*(void**)((char*)self + 0x1ac) + 0x190));
    playSE__9sndSystemF5SndIDiiii(g_sndSystem, 5, -1, 0, 0, -1);
}
