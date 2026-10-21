#pragma force_active on
typedef unsigned int u32;
typedef int s32;
typedef float f32;

extern "C" u32 fn_27_147D94(u32 unused, s32 id);
extern "C" void fn_27_2E4524(s32 a, f32 unused, f32 b, f32 c);
extern char g_ftCommonDataAccesser[];

class FtPad3c {
public:
    char pad[0x3c];
};

class FtPolyA : public FtPad3c {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual s32 getId();
};

class VObj {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual f32 v12(u32 id);
};

class VDone {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09();
};

extern "C" s32 fn_27_2DEB94(void* unused, s32 arg1, char* self) {
    FtPolyA* obj = *(FtPolyA**)(self + 0x8);
    s32 id = obj->getId();

    char* r31 = (char*)fn_27_147D94((u32)&g_ftCommonDataAccesser, id);

    VObj* p = *(VObj**)(*(char**)(self + 0xd8) + 0x64);
    f32 f = p->v12(0x21000004);

    VDone* c = *(VDone**)(*(char**)(self + 0xd8) + 0xc);
    c->v09();

    f32 unusedF;
    f32 q = f / *(f32*)(r31 + 0x0);
    fn_27_2E4524(arg1, unusedF, *(f32*)(r31 + 0xc), q);
    return 0;
}
