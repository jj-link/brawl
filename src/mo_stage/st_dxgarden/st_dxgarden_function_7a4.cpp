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
    void* p9c;
    char padA0[0x1a0 - 0xa0];
    void* archive;
};

extern "C" {
extern char lbl_77_data_0[];
Ground* fn_77_E10(int, const char*, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);

void fn_77_7A4(Stage* arg0, int arg1) {
    Ground* var_r31;
    char* data = lbl_77_data_0;

    switch (arg1) {
    case 1:
        var_r31 = fn_77_E10(5, data + 0xdc, data + 0xf0);
        break;
    case 2:
        var_r31 = fn_77_E10(7, data + 0x100, data + 0x108);
        break;
    case 5:
        var_r31 = fn_77_E10(0, data + 0x118, data + 0x120);
        break;
    case 7:
        var_r31 = fn_77_E10(9, data + 0x130, data + 0x148);
        break;
    case 10:
        var_r31 = fn_77_E10(3, data + 0x160, data + 0x174);
        break;
    default:
        var_r31 = 0;
        break;
    }
    if (var_r31 != 0) {
        addGround__5StageFP6Ground(arg0, var_r31);
        var_r31->startup(arg0->archive, 0, 0);
        var_r31->setValue(arg0->p9c);
    }
}
}
