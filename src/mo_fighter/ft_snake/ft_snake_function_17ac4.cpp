#pragma force_active on

struct Module {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual unsigned int getValue(int);
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual unsigned int hasLink(int);
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual int getState();
    virtual void v17();
    virtual void setFlag(int);
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
    virtual void changeState(int, void*);
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual unsigned int getLink(int);
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual unsigned int isLinked();
};

struct Modules {
    char pad0[0x54];
    Module* link;
    char pad58[0xC];
    Module* work;
    char pad68[8];
    Module* state;
};

struct Fighter {
    char pad0[0xD8];
    Modules* modules;
};

struct Context {
    char pad0[0x60];
    Fighter* fighter;
};

extern "C" void fn_122_1AF04(Fighter*);

extern "C" void fn_122_17AC4(Context* self) {
    switch (self->fighter->modules->state->getState()) {
    case 1:
        if (self->fighter->modules->link->hasLink(3) == 1) {
            Module* work = self->fighter->modules->work;
            Module* link = self->fighter->modules->link;
            if (link->getLink(3) == work->getValue(0x10000000)) {
                self->fighter->modules->work->setFlag(0x22000002);
            }
        }
        break;
    case 2:
        if (self->fighter->modules->link->hasLink(3) == 1) {
            Module* work = self->fighter->modules->work;
            Module* link = self->fighter->modules->link;
            if (link->getLink(3) == work->getValue(0x10000000)) {
                self->fighter->modules->work->setFlag(0x22000002);
            }
        }
        break;
    case 4:
    case 5:
        break;
    case 3:
    default:
        if (self->fighter->modules->link->isLinked() == 1) {
            fn_122_1AF04(self->fighter);
        }
        self->fighter->modules->state->changeState(0, self->fighter);
        break;
    }
}
