#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

struct Param {
    unsigned long a;
    unsigned long b;
    Vec3f pos;
};

struct Pad {
    unsigned char p[0x3c];
};

class Obj : public Pad {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
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
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62(Param* p, int n);
};

class Ground {
public:
    unsigned char pad0[0x14c];
    Obj* m_14c;
    unsigned char pad1[0x1ac - 0x150];
    unsigned long m_1ac;
    void getNodePosition(Vec3f* pos, unsigned long a, unsigned long b);
};

extern "C" void fn_62_FFDC(Ground* self) {
    Vec3f pos;
    Param p;
    p.a = 0x28;
    p.b = 0;
    self->getNodePosition(&pos, 0, self->m_1ac);
    p.pos = pos;
    Obj* obj = self->m_14c;
    obj->v62(&p, -1);
}
