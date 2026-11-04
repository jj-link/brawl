#pragma force_active on
typedef float f32;

struct ScnMdl {
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
    virtual void slot12(int n);
    char pad[0xE4 - 4];
    int count;
};

extern "C" {
void setFrameNode__8MuObjectFf(void*, f32);
void setFrameTex__8MuObjectFf(void*, f32);
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
int sprintf(char*, const char*, ...);
extern const char lbl_40_data_17C50[];
extern const double lbl_40_rodata_9A0;
}

extern "C" void fn_40_3F07C(char* self) {
    void* scn;
    void* obj;
    char* p28;
    char* p27;
    int i26;
    ScnMdl* mdl = *(ScnMdl**)(self + 0x938);
    int i24 = 0;
    char buf[8];
    while (mdl->count != 0) {
        if (mdl->count != 0) {
            mdl->slot12(mdl->count - 1);
        }
    }
    p28 = self;
    p27 = self;
    i26 = 0;
    while (i26 < *(int*)(self + 0x6f8) && i24 < 0xC) {
        int n = (*(int*)(p27 + 0xE4) + 6) / 7;
        obj = *(void**)(p28 + 0x71c);
        scn = *(void**)(p28 + 0x93c);
        setFrameNode__8MuObjectFf(obj, (f32)(n - 1));
        setFrameTex__8MuObjectFf(obj, (f32)*(int*)(p27 + 0x40));
        sprintf(buf, lbl_40_data_17C50, i24);
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(mdl, scn, buf);
        i24 += n;
        p28 += 4;
        p27 += 0xAC;
        i26++;
    }
}
