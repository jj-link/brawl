#pragma force_active on

struct Pad {
    char p[0x3c];
};

class Ground : public Pad {
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
    virtual void v37(void*, int, int);
    virtual void v38();
    virtual void v39(void*);
    void setDontMoveGround();
};

class Stage {
public:
    void addGround(Ground*);
};

extern "C" Ground* fn_47_1670(int, const char*, const char*);
extern char lbl_47_data_1C[];
extern char lbl_47_data_38[];

extern "C" void fn_47_4EC(Stage* stage, int arg) {
    Ground* ground;
    switch (arg) {
    case 0:
        ground = fn_47_1670(0, lbl_47_data_1C, lbl_47_data_38);
        break;
    default:
        ground = 0;
        break;
    }
    if (ground) {
        stage->addGround(ground);
        ground->v37(*(void**)((char*)stage + 0x1a0), 0, 0);
        ground->v39(*(void**)((char*)stage + 0x9c));
        ground->setDontMoveGround();
    }
}
