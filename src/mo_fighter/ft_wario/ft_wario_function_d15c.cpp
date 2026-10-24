#pragma force_active on

struct Vec3 {
    float x, y, z;
};

struct ObjA {
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7(const void*);
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12(float);
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
};

struct ObjB {
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual int v11(int);
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
    virtual Vec3 v38(int, int, bool);
    virtual void v39();
    virtual void v40();
    virtual int v41(int);
    virtual float v42(int);
};

struct ObjX {
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
    virtual void v42(int, int);
    virtual void v43(int);
};

struct Inner {
    char pad0[0xc];
    ObjA* a0c;
    char pad1[0x20 - 0x10];
    ObjX* a20;
    char pad2[0x54 - 0x24];
    ObjB* a54;
};

struct Holder {
    char pad[0xd8];
    Inner* inner;
};

extern "C" void fn_110_D15C(void*, Holder* h) {
    Inner* in = h->inner;
    ObjA* A = in->a0c;
    ObjB* B = in->a54;

    if (B->v11(6) != 0) {
        const Vec3& pos = B->v38(6, 0, 0);
        float f = B->v42(6);
        A->v7(&pos);
        A->v12(f);
        A->v21();

        if (B->v41(6) == 0) {
            h->inner->a20->v42(0, 0);
            return;
        }

        h->inner->a20->v43(0);
    }
}
