#pragma force_active on

struct Vec2f {
    float x, y;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int slot3();
    virtual void slot4();
    virtual void slot5(int, unsigned long);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual float slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13(float, unsigned long);
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual int slot17(unsigned long);
    virtual void slot18(unsigned long);
};

struct Modules {
    char pad0[0xc];
    Object_vptr_0* posture;
    char pad10[0x4];
    Object_vptr_0* x14;
    char pad18[0x4c];
    Object_vptr_0* work;
    char pad68[0x14];
    void* link;
};

struct Accesser {
    char pad0[0x8];
    void* obj;
    char padC[0xcc];
    Modules* modules;
    Object_vptr_0& getPosture() const { return *modules->posture; }
    Object_vptr_0& getWork() const { return *modules->work; }
};

struct Arg {
    char pad0[0xc];
    float x0c;
    char pad10[0x40];
    int x50;
    char pad54[0x28];
    float x7c;
    char pad80[0xc];
    Vec2f x8c;
};

struct Self {
    char pad0[8];
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
    char pad0c[0x30];
    Accesser* acc;
};

struct Effect {
    char pad0[4];
    float x04;
    char pad08[0x14];
    float x1c;
    char pad20[4];
    float x24;
};

extern "C" {
extern char lbl_41_data_644[];
extern char lbl_41_data_6A8[];
extern char __RTTI__5Enemy[];
extern char __RTTI__11StageObject[];
extern const float lbl_41_rodata_BEC;

void* __dynamic_cast(void*, long, const void*, const void*, short);
float getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*, unsigned long, unsigned long);
int getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(void*, unsigned long, unsigned long);
double cos(double);
double sin(double);
float fn_41_FEBC(Self*, float, int, int, bool, bool, Vec2f, float);
Vec2f fn_41_108CC(const Vec2f*, float);
Effect* fn_41_159AC(void*, int);
float fn_41_15A00(float, Vec2f);
void fn_41_11320(Self*, void*, void*, Object_vptr_0*, int, int, int*);
void fn_41_103FC(Self*, void*, Object_vptr_0*, float, Vec2f*, int, int, float, int);
int fn_41_FD44(Self*, float);
void fn_41_10008(Self*, Arg*, int, bool, bool);

void fn_41_11454(Self* self, Arg* arg) {
    Object_vptr_0* work;
    void* link;
    link = __dynamic_cast(self->acc->modules->link, 0, lbl_41_data_644, lbl_41_data_6A8, 1);
    Object_vptr_0* posture = &self->acc->getPosture();
    work = &self->acc->getWork();
    void* enemy = __dynamic_cast(self->acc->obj, 0x3c, __RTTI__5Enemy, __RTTI__11StageObject, 1);
    int kind = self->acc->modules->x14->slot3();
    float lr = posture->slot9();
    int flag = work->slot17(0x12000003);
    float scale = lbl_41_rodata_BEC * arg->x7c;
    float x7c = arg->x7c;
    float angle = fn_41_FEBC(self, arg->x0c, arg->x50, kind, false, false, arg->x8c, x7c);
    Vec2f dir;
    dir.x = scale * (float)cos(angle);
    dir.y = (float)sin(angle);
    float speed;
    if (kind == 0) {
        speed = getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(self->acc, 0xbe2, 0);
    } else {
        speed = getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(self->acc, 0xbe1, 0);
    }
    speed *= getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(self->acc, 0xbea, 0);
    dir = fn_41_108CC(&dir, speed);
    int value = getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(self->acc, 0x59d8, 0);
    int valueCopy = value;
    Effect* eff = fn_41_159AC(link, 8);
    if (eff != 0) {
        eff->x04 = speed;
        eff->x1c = speed;
        eff->x24 = fn_41_15A00(lr, dir);
    }
    fn_41_11320(self, enemy, link, posture, flag, value, &valueCopy);
    float power = arg->x0c * getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(self->acc, 0xbb8, 0);
    float scale2 = lbl_41_rodata_BEC * arg->x7c;
    int x50 = arg->x50;
    power *= getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(self->acc, 0xbd3, 0);
    power *= getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(self->acc, 0xbbb, 0);
    Vec2f vel;
    vel.x = scale2 * (power * (float)cos(angle));
    vel.y = power * (float)sin(angle);
    fn_41_103FC(self, link, posture, power, &vel, 0, x50, scale2, 1);
    work->slot5(value, 0x1000000D);
    work->slot13(arg->x0c, 0x11000009);
    work->slot5(valueCopy, 0x1000000C);
    work->slot18(0x22000005);
    fn_41_10008(self, arg, fn_41_FD44(self, (float)value), false, false);
    self->v30();
}
}
