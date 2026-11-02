#pragma force_active on

extern float lbl_27_rodata_224C;

struct T70 {
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
    virtual int v18();
};

struct T54 {
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10(int);
    virtual unsigned int v11(int);
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18(int, void*, int);
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
    virtual void v87(float*, float*);
    virtual void v88();
    virtual void v89(int);
    virtual unsigned int v90();
};

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3& o) : x(o.x), y(o.y), z(o.z) {}
};

struct CObj {
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual Vec3 v6();
    virtual void v7(Vec3*);
};

struct Sub {
    char pad0[0xC];
    CObj* c;
    char pad1[0x54 - 0x10];
    T54* p54;
    char pad2[0x70 - 0x58];
    T70* p70;
};

struct Object {
    char pad[0xD8];
    Sub* sub;
};

extern "C" void fn_27_1710D8(void*, Object* obj) {
    int r = obj->sub->p70->v18();
    switch (r) {
    case 0x6D:
        if (obj->sub->p54->v11(3) == 1) {
            if (obj->sub->p54->v90() == 1) {
                float v2[3];
                float v1[3];
                float z = lbl_27_rodata_224C;
                v2[0] = z;
                v2[1] = z;
                v2[2] = z;
                v1[0] = z;
                v1[1] = z;
                v1[2] = z;
                obj->sub->p54->v87(v1, v2);
                obj->sub->p54->v89(1);
                Vec3 pos = obj->sub->c->v6();
                pos.z = lbl_27_rodata_224C;
                obj->sub->c->v7(&pos);
            }
            obj->sub->p54->v10(3);
        }
        return;
    case 0x6E:
    case 0x70: {
        struct {
            int a;
            char b;
        } s;
        s.a = 7;
        s.b = 0;
        obj->sub->p54->v18(3, &s, 0);
        return;
    }
    case 0x6F:
        return;
    case 0x71:
        return;
    default:
        return;
    }
}
