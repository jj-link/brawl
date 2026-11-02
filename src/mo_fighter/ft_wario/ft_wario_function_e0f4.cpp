#include <so/kinetic/so_kinetic_module_impl.h>
#include <so/kinetic/so_kinetic_energy.h>
#include <mt/mt_vector.h>

#pragma force_active on

extern "C" {
extern const unsigned char lbl_110_data_6098[];
extern const unsigned char lbl_110_data_617C[];
extern const unsigned char lbl_110_data_168C[];
extern const float lbl_110_rodata_48;

void* __dynamic_cast(void*, long, const void*, const void*, short);
}

struct Pair {
    float x;
    float y;
};

struct QueryArg {
    int id;
    unsigned char flag;
    Pair out;
};

struct Obj54 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(int);
    virtual int check(int);
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14();
    virtual void query(int, QueryArg*);
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
    virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67();
    virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75();
    virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
    virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83();
    virtual void v84(); virtual void v85(); virtual void v86();
    virtual void set(int);
};

struct ModuleView {
    unsigned char pad0[0x54];
    Obj54* obj;
    unsigned char pad58[0x24];
    soKineticModule* kinetic;
};

struct AccessView {
    unsigned char pad0[0xd8];
    ModuleView* modules;
};

struct EnergyFields {
    unsigned char pad0[8];
    float x;
    float y;
    float z;
};

extern "C" void fn_110_E0F4(void*, AccessView* accesser) {
    ModuleView* modules = accesser->modules;
    soKineticModule* kinetic = modules->kinetic;
    Obj54* obj = modules->obj;

    if (obj->check(6)) {
        QueryArg arg;
        arg.id = 0x458;
        arg.flag = 0;
        obj->query(6, &arg);
        Pair v = arg.out;

        EnergyFields* fields0 = static_cast<EnergyFields*>(__dynamic_cast(
            kinetic->getEnergy(3), 0, lbl_110_data_6098, lbl_110_data_168C, 1));
        EnergyFields* fields1 = static_cast<EnergyFields*>(__dynamic_cast(
            kinetic->getEnergy(1), 0, lbl_110_data_617C, lbl_110_data_168C, 1));

        Pair speed;
        speed.x = v.x;
        speed.y = lbl_110_rodata_48;
        fields0->x = speed.x;
        fields0->y = speed.y;
        fields1->y = v.y;
        obj->set(1);
        obj->v8(6);
    }
}
