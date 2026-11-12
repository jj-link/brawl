#pragma force_active on

extern "C" {
extern const char lbl_122_data_83E4[], lbl_122_data_8C98[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_111364(void*);
void fn_122_1FA10(void*, unsigned int, unsigned int, int, float);
}

#define V8(n) \
    virtual void n##0(); virtual void n##1(); \
    virtual void n##2(); virtual void n##3(); \
    virtual void n##4(); virtual void n##5(); \
    virtual void n##6(); virtual void n##7();

class FighterPrimary {
public:
    char pad[0x28];
    unsigned int taskId;
};

class Fighter {
public:
    char pad0[0x28];
    unsigned int taskId;
    char pad2c[0x10];
    V8(a) V8(b) V8(c) V8(d) V8(e) V8(f) V8(g) V8(h) V8(i) V8(j)
    V8(k) V8(l) V8(m) V8(n) V8(o) V8(p) V8(q) V8(r) V8(s) V8(t)
    V8(u) V8(v) V8(w)
    virtual void x0();
    virtual void* getOwner();
};

class ResIdObj {
public:
    V8(a) V8(b) V8(c) V8(d) V8(e)
    virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43();
    virtual float getFloat();
};

class ResModObj {
public:
    char pad[8];
    virtual void s0();  virtual void s1();  virtual void s2();  virtual void s3();
    virtual void* getResourceIdAccesser();
};

class Accesser2 {
public:
    virtual void a0(); virtual void a1(); virtual void a2();
    virtual void a3(); virtual void a4(); virtual void a5();
    virtual void a6(); virtual void a7(); virtual void a8();
    virtual void a9(); virtual void a10(); virtual void a11();
    virtual void a12(); virtual void a13(); virtual void a14();
    virtual unsigned int getEtcResId();
};

class Modules {
public:
    ResModObj* resModObj;
    char pad4[0x1c - 4];
    ResIdObj* resId;
};

class Accesser {
public:
    char pad0[8];
    void* stageObject;
    char pad8[0xcc];
    Modules* modules;
};

extern "C" int fn_122_DD10(void* arg0, Accesser* arg1) {
    Fighter* fighter = static_cast<Fighter*>(__dynamic_cast(
        arg1->stageObject, 0x3c, lbl_122_data_83E4, lbl_122_data_8C98, short(1)));
    Modules* modules = arg1->modules;
    ResModObj* resModObj = modules->resModObj;
    unsigned int taskId = static_cast<FighterPrimary*>(arg1->stageObject)->taskId;
    ResIdObj* resId = modules->resId;
    float value = resId->getFloat();
    int ownerId = fn_27_111364(fighter->getOwner());
    unsigned int res = static_cast<Accesser2*>(resModObj->getResourceIdAccesser())->getEtcResId();
    fn_122_1FA10(arg0, taskId, res, ownerId, value);
    return 1;
}
