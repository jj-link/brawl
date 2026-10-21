#pragma force_active on
struct Ground {
    char pad[0x3c];
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
    virtual void startup(void*, int, int);
    virtual void v38();
    virtual void setValue(void*);
};

struct Stage {
    char pad0[0x9c];
    void* value;
    char padA0[0x1a0 - 0xa0];
    void* archive;
};

extern "C" {
extern char lbl_60_data_0[];
Ground* fn_60_6348(int, const char*, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);

void fn_60_1BD0(Stage* stage, int kind) {
    Ground* ground;
    char* data = lbl_60_data_0;
    switch (kind) {
    case 0:
        ground = fn_60_6348(4, data + 0x118, data + 0x1e8);
        break;
    case 1:
        ground = fn_60_6348(5, data + 0x118, data + 0x1f4);
        break;
    default:
        ground = 0;
        break;
    }
    if (ground) {
        addGround__5StageFP6Ground(stage, ground);
        ground->startup(stage->archive, 0, 0);
        ground->setValue(stage->value);
    }
}
}
