#pragma force_active on
struct MuMsg {
    void printf(unsigned long, const char*, ...);
};

enum SndID { SND_6 = 6 };

struct sndSystem {
    void playSE(SndID, int, int, int, int);
};

struct Base0x3c {
    char pad[0x3c];
};

struct Poly : Base0x3c {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42();
    virtual void g(void*);
};

extern void* g_sndSystem;
extern char lbl_6_data_0[];

extern "C" {
void fn_6_6520(char* self) {
    ((MuMsg*)(*(void**)(*(char**)(self + 0x1ac) + 0x1c7c)))->printf(0xf, lbl_6_data_0);

    ((Poly*)self)->g(*(void**)(*(char**)(self + 0x1ac) + 0x190));

    ((sndSystem*)g_sndSystem)->playSE(SND_6, -1, 0, 0, -1);
}
}
