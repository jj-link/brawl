#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

struct Entity {
    unsigned char pad[0x3C];
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63();
    virtual void m64();
    virtual void m65(float);
    virtual void m66(float, int);
};

extern "C" {
extern const float lbl_84_rodata_28;
void setPos__9grGimmickFP5Vec3f(void*, Vec3f*);
void setScale__9grGimmickFP5Vec3f(void*, Vec3f*);
void startEntityAutoLoop__8grMadeinFv(void*);
}

extern "C" void fn_84_14F8(void* object, unsigned int index, float x, float y, float scale, unsigned char state) {
    unsigned char* entry = (unsigned char*)object + (index << 5);

    if (entry[0x220] != 0) {
        return;
    }

    *(float*)(entry + 0x224) = x;
    *(float*)(entry + 0x228) = y;
    *(float*)(entry + 0x22C) = lbl_84_rodata_28;
    *(float*)(entry + 0x230) = lbl_84_rodata_28;
    *(float*)(entry + 0x238) = scale;
    *(float*)(entry + 0x234) = scale;

    Vec3f vector;
    vector.x = x;
    vector.y = y;
    vector.z = lbl_84_rodata_28;
    void* entity = *(void**)(entry + 0x23C);
    setPos__9grGimmickFP5Vec3f(entity, &vector);

    vector.x = scale;
    vector.y = scale;
    vector.z = scale;
    entity = *(void**)(entry + 0x23C);
    setScale__9grGimmickFP5Vec3f(entity, &vector);

    entry[0x220] = state;
    entity = *(void**)(entry + 0x23C);
    startEntityAutoLoop__8grMadeinFv(entity);

    entity = *(void**)(entry + 0x23C);
    ((Entity*)entity)->m65(lbl_84_rodata_28);

    entity = *(void**)(entry + 0x23C);
    ((Entity*)entity)->m66(lbl_84_rodata_28, 0);
}
