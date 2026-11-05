#pragma force_active on
typedef unsigned long long u64;
struct Vec { float x, y; };
union Pair { u64 value; Vec vec; };
struct Module {
    char pad[8];
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
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual u64 get1(int, int);
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual int flags(int);
    virtual void v62();
    virtual u64 get2(int, int);
};
struct Access { char pad[0x10]; Module* module; };
struct Object { char pad[0xd8]; Access* access; };
extern "C" int fn_27_195528(Object* obj, Vec* a, Vec* b) {
    int flags = obj->access->module->flags(0);
    if (flags) {
        if (flags & 8) {
            Pair p; p.value = obj->access->module->get2(8, 0);
            *a = p.vec;
            Pair q; q.value = obj->access->module->get1(8, 0);
            *b = q.vec;
        } else if (flags & 1) {
            Pair p; p.value = obj->access->module->get2(1, 0);
            *a = p.vec;
            Pair q; q.value = obj->access->module->get1(1, 0);
            *b = q.vec;
        } else if (flags & 2) {
            Pair p; p.value = obj->access->module->get2(2, 0);
            *a = p.vec;
            Pair q; q.value = obj->access->module->get1(2, 0);
            *b = q.vec;
        } else if (flags & 4) {
            Pair p; p.value = obj->access->module->get2(4, 0);
            *a = p.vec;
            Pair q; q.value = obj->access->module->get1(4, 0);
            *b = q.vec;
        }
    }
    return flags;
}