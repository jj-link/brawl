#include <types.h>
#pragma force_active on

#define MOD(a, off) (*(void**)(*(u8**)((u8*)(a) + 0xd8) + (off)))

struct Vec2f {
    float x;
    float y;
};

struct Vec3f {
    float x;
    float y;
    float z;
};

struct Pair {
    s32 a;
    s32 b;
};

struct Blk {
    s32 id;
    float a;
    float b;
    u8 c[4];
};

struct VA {
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual float v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual Pair v15(void*);
    virtual void v16();
    virtual void v17();
    virtual s32 v18();
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
    virtual void v32(void*);
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41(s32, s32, s32, s32, s32, float, float);
};

struct VB {
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15(u32, float);
};

extern "C" {
extern const float lbl_27_rodata_2078[];
void* getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(void* self, u32 a, u32 b);
void fn_27_89D08(int, void*, int, Vec2f*, Vec3f*);
void fn_27_89DAC(int, void*);
}

extern "C" void fn_27_167EF4(void* unused, void* acc) {
    const float* lbl = lbl_27_rodata_2078;
    if (((VA*)MOD(acc, 0x70))->v18() == 0x85) {
        float* v = (float*)getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0x10000 - 0x57F5, 0);
        float scale = ((VA*)MOD(acc, 0x0c))->v11();
        short flag = 1;
        Pair p;
        Pair tmp = ((VA*)MOD(acc, 0x7c))->v15(&flag);
        p = tmp;
        ((VB*)MOD(acc, 0x64))->v15(0x21000005, v[5]);
        ((VB*)MOD(acc, 0x64))->v15(0x21000006, -*(float*)&p.b);
        Vec3f rot;
        rot.x = lbl[0];
        rot.y = lbl[0];
        rot.z = lbl[0];
        Vec2f speed;
        speed.x = v[5] * scale;
        speed.y = lbl[0];
        fn_27_89D08(3, acc, 0x16, &speed, &rot);
        fn_27_89DAC(2, acc);
        fn_27_89DAC(0, acc);
        fn_27_89DAC(1, acc);
        Blk blk;
        blk.id = 0x3a;
        blk.a = lbl[1];
        blk.b = lbl[0];
        blk.c[0] = 0;
        blk.c[1] = 0;
        blk.c[2] = 0;
        blk.c[3] = 0;
        ((VA*)MOD(acc, 0x08))->v32(&blk);
        ((VA*)MOD(acc, 0x08))->v41(1, 0x3b, ((s32*)v)[0x14], 0, 0, lbl[0], lbl[2]);
    }
}
