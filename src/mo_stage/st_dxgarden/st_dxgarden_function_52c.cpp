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
};

class Stage {
public:
    void addGround(Ground* g);
};

extern "C" Ground* fn_77_1140(int, const char*, const char*);
extern char lbl_77_data_50[];
extern char lbl_77_data_60[];

extern "C" void fn_77_52C(Stage* stage, int type) {
    Ground* ground;
    switch (type) {
    case 4:
        ground = fn_77_1140(4, lbl_77_data_50, lbl_77_data_60);
        break;
    default:
        ground = 0;
        break;
    }
    if (ground) {
        stage->addGround(ground);
        ground->v37(*(void**)((char*)stage + 0x1a0), 0, 0);
        ground->v39(*(void**)((char*)stage + 0x9c));
    }
}
