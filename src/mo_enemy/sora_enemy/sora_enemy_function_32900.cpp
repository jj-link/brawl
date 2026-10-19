#pragma force_active on
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}
};

struct BaseData {
    char pad[0x3C];
};

struct Base : BaseData {
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual unsigned int getKind();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual int test(int);
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void set(int);
};

struct Ground {
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual Vec3 getPosition();
};

struct GroundOwner {
    char pad[0x0C];
    Ground* ground;
};

struct Modules {
    char pad[0xD8];
    GroundOwner* owner;

    Ground& groundModule() { return *owner->ground; }
};

struct Object {
    char pad0[0xC];
    Base base;
    char pad4C[0x6C - 0x4C];
    Modules* modules;
    char pad70[0x21BA - 0x70];
    unsigned char enabled;
    char pad21BB[0x21E0 - 0x21BB];
    float x, y;
};

extern "C" void fn_27_5CA4(Base*);
extern "C" const float lbl_41_rodata_E28;
extern "C" int checkDeadArea__12soGroundUtilFP5Vec3fff(Vec3*, float, float);
extern "C" void fn_27_8CF84(void*, Modules*);
extern "C" char lbl_41_data_4A54[];
extern "C" void wnemReport__FPCce(const char*, ...);

extern "C" void fn_41_32900(Object* obj) {
    fn_27_5CA4(&obj->base);
    obj->x = lbl_41_rodata_E28;
    obj->y = lbl_41_rodata_E28;
    if (obj->enabled && !obj->base.test(0)) {
        Vec3 pos = obj->modules->groundModule().getPosition();
        if (checkDeadArea__12soGroundUtilFP5Vec3fff(
                &pos, lbl_41_rodata_E28, lbl_41_rodata_E28) != -1) {
            fn_27_8CF84((char*)obj + 0x94, obj->modules);
            if (obj->base.getKind() == 1) {
                wnemReport__FPCce(lbl_41_data_4A54);
                obj->base.set(0);
            }
        }
    }
}
