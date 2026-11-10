#include <types.h>

#pragma force_active on

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" char lbl_27_data_2E5F8[];
extern "C" char lbl_27_data_CDF8[];
extern "C" float lbl_27_rodata_2348;

class Energy {
public:
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
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
};

class Kinetic {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual Energy* get(int);
};

class Work {
public:
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
    virtual void set(int, int);
};

struct Modules {
    char pad0[0x40];
    Work* module40;
    char pad44[0x38];
    Kinetic* module7C;
};

struct Obj {
    char pad00[0xD8];
    Modules* modules;
};

extern "C" void fn_27_179DB0(void* self, Obj* obj, int status) {
    float fsp[2];
    switch (status) {
    case 0x3d:
    case 0x3e:
    case 0x3f:
    case 0x42:
    case 0xd9:
    case 0xda:
    case 0x107:
    case 0x108:
    case 0x109:
        return;
    default:
        break;
    }

    Kinetic* kin = obj->modules->module7C;
    Energy* e = kin->get(3);
    Energy* energy = (Energy*)__dynamic_cast(e, 0, lbl_27_data_2E5F8, lbl_27_data_CDF8, 1);

    fsp[0] = lbl_27_rodata_2348;
    fsp[1] = lbl_27_rodata_2348;
    *(float*)((char*)energy + 0x8) = fsp[0];
    *(float*)((char*)energy + 0xc) = fsp[1];

    Work* w = obj->modules->module40;
    w->set(0, 0);
}
