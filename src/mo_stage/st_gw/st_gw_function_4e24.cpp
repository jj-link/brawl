#pragma force_active on

struct Vec {
    float x, y, z;
};

struct Vec3 : Vec {
    Vec3(const Vec& other) {
        x = other.x;
        y = other.y;
        z = other.z;
    }
};

struct Status {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};

struct Modules {
    char pad[0x14];
    Status* status;
};

struct BaseItem {
    char pad[0x1A4];
    Modules* modules;
};

extern "C" {
void* getInstance__9itManagerFv();
BaseItem* getItemFromInstanceId__9itManagerFi(void*, int);
int fn_27_28DC8C(BaseItem*);
float getParamFloat__8BaseItemFUl(BaseItem*, unsigned long);
Vec getPos__23soExternalValueAccesserFP11StageObject(BaseItem*);

extern const float lbl_63_rodata_54;
extern const float lbl_63_rodata_78;

int fn_63_4E24(void*, int id) {
    if (id == 0)
        return 0;

    void* manager = getInstance__9itManagerFv();
    if (manager == 0)
        return 0;

    BaseItem* item = getItemFromInstanceId__9itManagerFi(manager, id);
    if (item == 0)
        return 0;

    if (fn_27_28DC8C(item) == 0)
        return 0;

    if (item->modules->status->v3() == 2)
        return 0;

    if (lbl_63_rodata_54 != getParamFloat__8BaseItemFUl(item, 0x3EE))
        return 0;

    Vec3 pos = getPos__23soExternalValueAccesserFP11StageObject(item);
    return (pos.y > lbl_63_rodata_78) == 0;
}
}
