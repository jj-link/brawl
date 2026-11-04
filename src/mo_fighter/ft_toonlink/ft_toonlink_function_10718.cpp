#pragma force_active on
extern "C" {
extern const float lbl_121_rodata_6C;
extern const char lbl_121_data_3110[], lbl_121_data_31F4[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}
struct Params {
    int kind;
    unsigned char flag;
    int a, b, c, d;
    float value;
    unsigned char enabled;
};
struct State { int fields[7]; };
extern "C" void fn_121_100DC(State*);
class Work {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void setInt(int, unsigned int);
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14(); virtual void v15(); virtual void v16();
    virtual bool isFlag(unsigned int);
    virtual void onFlag(unsigned int);
};
class Link {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual bool check(int);
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14(); virtual void v15();
    virtual void send(int, void*, int);
    virtual void v17(); virtual void v18();
    virtual int get(int);
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
    virtual void v96(); virtual void v97(); virtual void v98();
    virtual void disconnect(int, bool, bool);
};
class Status {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual bool check();
};
class Control {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void first(); virtual void v6(); virtual void second();
};
class Kinetic {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void* getEnergy(int);
};
struct Modules {
    char pad[0x3c]; Status* status; char pad40[4]; Control* control;
    char pad48[0xc]; Link* link; char pad58[0xc]; Work* work;
    char pad68[0x14]; Kinetic* kinetic;
};
struct Fighter { char pad[0xd8]; Modules* modules; };
struct Energy { char pad[5]; unsigned char active : 1; };
extern "C" void fn_121_10718(void*, Fighter* fighter) {
    Work* work = fighter->modules->work;
    Status* status = fighter->modules->status;
    fighter->modules->control->first();
    fighter->modules->control->second();
    if (fighter->modules->link->check(2))
        fighter->modules->link->disconnect(2, 0, 0);
    if (work->isFlag(0x22000012) && !work->isFlag(0x22000013) && status->check()) {
        State p;
        fn_121_100DC(&p);
        p.fields[2] = 4;
        fighter->modules->link->send(0, &p, 0);
        work->onFlag(0x22000013);
    }
    if (work->isFlag(0x22000014) && !work->isFlag(0x22000015) && status->check()) {
        Params p;
        p.kind = 11;
        p.flag = 0;
        p.a = 0xa3;
        p.b = -1;
        p.c = -1;
        p.d = -1;
        p.value = lbl_121_rodata_6C;
        p.enabled = 1;
        fighter->modules->link->send(0, &p, 0);
        Work* w = fighter->modules->work;
        w->setInt(fighter->modules->link->get(0), 0x20000002);
        fighter->modules->work->setInt(p.b, 0x20000003);
        fighter->modules->work->setInt(p.c, 0x20000004);
        work->onFlag(0x22000015);
        State q;
        fn_121_100DC(&q);
        q.fields[2] = 5;
        fighter->modules->link->send(0, &q, 0);
    }
    Energy* energy = (Energy*)__dynamic_cast(fighter->modules->kinetic->getEnergy(1), 0, lbl_121_data_3110, lbl_121_data_31F4, 1);
    if (work->isFlag(0x22000016))
        energy->active = 1;
    else
        energy->active = 0;
}