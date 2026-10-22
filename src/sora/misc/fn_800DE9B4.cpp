#pragma force_active on

class gfModelAnimation {
public:
    void setUpdateRate(float rate);
};

extern "C" void fn_800B753C(void* self, float rate);
extern const float lbl_805A2368;
extern const float lbl_805A2374;

class Obj {
public:
    virtual void s00();
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
    virtual void s10();
    virtual void s11(void*, void*);
    virtual void s12();
    virtual void s13(void*);
};

extern "C" void fn_800DE9B4(void* arg0) {
    char* base = (char*)arg0;
    int i;
    void* anim = *(void**)(base + 0x4C);
    ((gfModelAnimation*)*(void**)((char*)anim + 0x14))->setUpdateRate(lbl_805A2368);
    fn_800B753C(anim, lbl_805A2374);
    char* p = base + 0x34;
    for (i = 0xD; i < 0x18; i++, p += 4) {
        void* e = *(void**)(p + 0x10);
        if (e != 0) {
            Obj* o = *(Obj**)(base + 0x8);
            o->s13(*(void**)((char*)e + 0x10));
        }
    }
    Obj* o = *(Obj**)(base + 0x8);
    o->s11(*(void**)((char*)o + 0xE4), *(void**)((char*)anim + 0x10));
}
