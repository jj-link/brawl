#include <so/event/so_event_system.h>
#pragma force_active on

struct List;

struct Elem {
    virtual void e0();
    virtual unsigned int e1(void*, void*, int, int);
};

struct List {
    virtual void l0();
    virtual void l1();
    virtual Elem** l2(int);
    virtual void l3();
    virtual int l4();
};

struct Unit {
    virtual void u0();
    virtual void u1();
    virtual void u2();
    virtual void u3();
    virtual void u4();
    virtual void u5();
    virtual void u6();
    virtual List* u7();
};

struct Instance {
    virtual void i0();
    virtual void i1();
    virtual void i2();
    virtual void i3();
    virtual void i4();
    virtual void i5();
    virtual int i6(int);
};

struct Manager {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual int m4(int);
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void* m8(int);
};

struct Object_vptr_0 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual int slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
};

struct Arg {
    char pad[0x28];
    void* value;
};

struct ModBase {
    char pad[8];
};

struct Mod : ModBase {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
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
    virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87();
    virtual void v88(); virtual void v89(); virtual void v90(); virtual void v91();
    virtual void v92(); virtual void v93(); virtual void v94(); virtual void v95();
    virtual void v96(); virtual void v97(); virtual void v98(); virtual void v99();
    virtual void v100(); virtual void v101(); virtual void v102(); virtual void v103();
    virtual void v104(); virtual void v105(); virtual void v106(); virtual void v107();
    virtual void v108(); virtual void v109(); virtual void v110(); virtual void v111();
    virtual void v112(); virtual void v113(); virtual void v114(); virtual void v115();
    virtual void v116(); virtual void v117(); virtual void v118(); virtual void v119();
    virtual int check(Arg*, int);
};

struct Modules {
    char pad[0x10];
    Mod* mod;
    char pad2[0x28];
    Object_vptr_0* object;
};

struct Owner {
    char pad[0xd8];
    Modules* modules;
};

class Class_7618 {
public:
    virtual void fn_27_66114();
    virtual void fn_27_66154();
    virtual void fn_27_661B4();
    virtual void fn_27_661B8();
    virtual void fn_27_661C8();
    virtual int fn_27_661D4();
    virtual void fn_27_66284();
    virtual void fn_27_6636C();
    virtual void fn_27_665FC();
    virtual void fn_27_666AC();
    virtual void fn_27_666FC();
    virtual void fn_27_66864();
    virtual void fn_27_669B0();
    virtual void fn_27_66A70();
    virtual void fn_27_66BD4();
    virtual void fn_27_66BDC();
    virtual void fn_27_66CBC();
    virtual void fn_27_66E08();
    virtual void fn_27_66F58();
    virtual void fn_27_67250();
    virtual void fn_27_67248();
    virtual void fn_27_67240();
    virtual void fn_27_67238();
    virtual void fn_27_67230();
    virtual void fn_27_67228();
    virtual int fn_27_67218();

    int pad;
    short id1;
    short id2;
    List* cached;
    Owner* owner;
    char pad2[0x1c];
    char flag;
};

struct SelfId {
    char pad[8];
    int ids;
};

extern "C" {
extern char lbl_27_bss_B80[];
extern char lbl_27_data_7608[];
extern char __RTTI__11soEventUnit[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

inline bool checkIdHelper(const short* id, int& temp) {
    temp = *id;
    return soEventSystem::getInstance()->getInstanceManager().isContain(temp);
}

inline List* selectList(Class_7618* self) {
    short id1 = *(short*)&((SelfId*)self)->ids;
    int id2;
    Manager* mgr;
    List* cur;
    Unit* unit;
    int flag;

    if (id1 <= -1)
        return (List*)lbl_27_bss_B80;

    if (self->cached != 0)
        goto C;

    if (self->id1 <= -1 ||
        !checkIdHelper(&self->id1, id2)) {
        flag = 0;
        goto CHECK;
    }

    if (((Manager*)soEventSystem::getInstance()->getManager(self->id1))->m4(self->id2) == 0) {
        self->cached = 0;
        flag = 0;
        goto CHECK;
    }

    id2 = self->id2;
    mgr = (Manager*)soEventSystem::getInstance()->getManager(self->id1);
    if (mgr->m4(id2) == 0) {
        cur = 0;
    } else {
        unit = (Unit*)__dynamic_cast(
            mgr->m8(id2), 0, lbl_27_data_7608, __RTTI__11soEventUnit, 0);
        if (unit == 0)
            cur = 0;
        else
            cur = unit->u7();
    }

    self->cached = cur;
    flag = (cur != 0);

CHECK:
    if (flag == 0)
        return (List*)lbl_27_bss_B80;

C:
    mgr = (Manager*)soEventSystem::getInstance()->getManager(self->id1);
    if (mgr->m4(self->id2) == 0) {
        self->cached = 0;
        return (List*)lbl_27_bss_B80;
    }
    return self->cached;
}

extern "C" int fn_27_66F58(Class_7618* self, Arg* arg, int a, int b) {
    if (self->fn_27_661D4() == 0 &&
        (self->owner->modules->object->slot6() == 0 || self->fn_27_67218() != 0) &&
        self->owner->modules->mod->check(arg, 0) == 0) {
        void* value = arg->value;
        List* list = selectList(self);

        for (int i = 0; i < list->l4(); i++) {
            if ((*list->l2(i))->e1(self->owner, value, a, b) == 1) {
                self->flag = 1;
                return 1;
            }
        }
    }
    return 0;
}
