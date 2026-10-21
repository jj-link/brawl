#pragma force_active on

typedef unsigned int u32;

struct Msg {
    int id;
    unsigned char flag;
};

class Comp {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(u32);
    virtual u32 v9(u32);
    virtual u32 v10(u32);
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16(u32, Msg*, u32);
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
    virtual void v87(u32);
};

class Other {
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
};

struct Modules {
    char pad[0x3c];
    Other* other;
    char pad40[0x14];
    Comp* comp;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

struct Object {
    char pad[0x60];
    Accesser* accesser;
};

extern "C" void fn_27_29E64C(void*, Object* obj) {
    if (obj->accesser->modules->comp->v10(0) == 1U) {
        Msg msg;
        msg.id = 0x34;
        msg.flag = 0;
        obj->accesser->modules->comp->v16(0, &msg, 0);
    }

    if (obj->accesser->modules->comp->v9(0) == 1U) {
        obj->accesser->modules->comp->v87(1);
        obj->accesser->modules->comp->v8(0);
    }

    obj->accesser->modules->other->v8();
}
