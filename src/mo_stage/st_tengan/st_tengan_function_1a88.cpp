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
    char pad2[0x44 - 0x40];
};
struct Ground2 : Ground {
    int** p44;
};

struct Stage {
    char pad0[0x9c];
    void* value;
    char padA0[0x1a0 - 0xa0];
    void* archive;
};

extern char lbl_60_data_0[];
extern "C" {
Ground2* create__8grMadeinFiPCcPCcQ25Heaps8HeapType(int, const char*, const char*, int);
void addGround__5StageFP6Ground(Stage*, Ground*);
void initializeEntity__8grMadeinFv(Ground*);
void fn_801AAFF0(void*, int);
void fn_801AB014(void*, int);

void fn_60_1A88(Stage* stage, int kind) {
    Ground2* g;
    char* data = lbl_60_data_0;
    switch (kind) {
    case 11:
        g = create__8grMadeinFiPCcPCcQ25Heaps8HeapType(11, data + 0x144, data + 0x158, 15);
        break;
    case 12:
        g = create__8grMadeinFiPCcPCcQ25Heaps8HeapType(12, data + 0x16c, data + 0x180, 15);
        break;
    case 13:
        g = create__8grMadeinFiPCcPCcQ25Heaps8HeapType(13, data + 0x198, data + 0x1a8, 15);
        break;
    case 14:
        g = create__8grMadeinFiPCcPCcQ25Heaps8HeapType(14, data + 0x1b8, data + 0x1d0, 15);
        break;
    default:
        g = 0;
        break;
    }
    if (g) {
        addGround__5StageFP6Ground(stage, g);
        g->startup(stage->archive, 0, 0);
        g->setValue(stage->value);
        initializeEntity__8grMadeinFv(g);
        fn_801AAFF0(*g->p44, 255);
        fn_801AB014(*g->p44, 255);
    }
}
}
