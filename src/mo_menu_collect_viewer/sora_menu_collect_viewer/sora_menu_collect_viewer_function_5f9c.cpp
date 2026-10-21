#pragma force_active on

struct Pad {
    char pad[0x3c];
};

class Viewer : public Pad {
public:
    virtual void v0();  virtual void v1();  virtual void v2();  virtual void v3();
    virtual void v4();  virtual void v5();  virtual void v6();  virtual void v7();
    virtual void v8();  virtual void v9();  virtual void v10(); virtual void v11();
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
};

extern "C" {
void fn_6_604C(int* p);
void fn_800C2BB4(void* p, int v);

void fn_6_5F9C(unsigned char* self) {
    unsigned char* obj;
    unsigned char* inner;
    int sp8;

    obj = *(unsigned char**)(self + 0x1ac);
    inner = *(unsigned char**)(obj + 0x1ce4);
    if (*(int*)(inner + 0x350) == 0) {
        if (*(int*)(inner + 0x354) == 0) {
            int v;
            unsigned char* p;
            fn_6_604C(&sp8);
            p = *(unsigned char**)(self + 0x1ac) + 0x1cf0;
            v = sp8;
            sp8 = 0;
            fn_800C2BB4(p, v);
            fn_800C2BB4(&sp8, 0);
            obj = *(unsigned char**)(self + 0x1ac);
            *(int*)(obj + 0x1cf4) =
                *(int*)(*(unsigned char**)(obj + 0x1ce4) + 0x1a4);
            obj = *(unsigned char**)(self + 0x1ac);
            *(int*)(obj + 0x1bfc) = 6;
            return;
        } else {
            ((Viewer*)self)->v75();
            obj = *(unsigned char**)(self + 0x1ac);
            *(int*)(obj + 0x1bfc) = 0;
        }
    }
}
}
