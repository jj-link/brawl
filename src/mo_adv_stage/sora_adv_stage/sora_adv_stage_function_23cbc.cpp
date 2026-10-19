#pragma force_active on
struct Vec3 {
    float x;
    float y;
    float z;
};

struct Prefix {
    char padding[0x38];
};

struct Base {
    virtual void slot0(unsigned long);
    virtual void slot1(unsigned long);
    virtual void slot2(unsigned long);
    virtual void slot3(unsigned long);
    virtual void slot4(unsigned long);
    virtual void slot5(unsigned long);
    virtual void slot6(unsigned long);
    virtual void slot7(unsigned long);
    virtual void slot8(unsigned long);
    virtual void slot9(unsigned long);
    virtual void slot10(unsigned long);
    virtual void slot11(unsigned long);
    virtual void slot12(unsigned long);
    virtual void slot13(unsigned long);
    virtual void slot14(unsigned long);
    virtual void slot15(unsigned long);
    virtual void slot16(unsigned long);
    virtual void slot17(unsigned long);
    virtual void slot18(unsigned long);
    virtual void slot19(unsigned long);
    virtual void slot20(unsigned long);
    virtual void slot21(unsigned long);
    virtual void slot22(unsigned long);
    virtual void slot23(unsigned long);
    virtual void slot24(unsigned long);
};

struct Object : Prefix, Base {
    virtual void slot24(unsigned long);
};

extern "C" {
void setEnableCollisionStatus__6GroundFb(void*, bool);
void startGimmickSE__9grGimmickFUl(void*, unsigned long);
void startGimmickEffect__9grGimmickFUl(void*, unsigned long);
void getPos__9grGimmickFv(Vec3*, void*);
void* fn_8009D2DC();
void fn_8009D564(void*, unsigned long, Vec3*);
}

extern "C" void fn_40_23CBC(void* self)
{
    Vec3 pos;

    ((Object*)self)->slot24(0);
    setEnableCollisionStatus__6GroundFb(self, false);
    startGimmickSE__9grGimmickFUl(self, 0);
    startGimmickEffect__9grGimmickFUl(self, 0);
    getPos__9grGimmickFv(&pos, self);
    fn_8009D564(fn_8009D2DC(), 3, &pos);
}
