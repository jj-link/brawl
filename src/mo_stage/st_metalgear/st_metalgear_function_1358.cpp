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
    virtual void v40();
    virtual void v41(void*);
};

struct Stage {
    char pad0[0x9c];
    void* value;
    char padA0[0x1a0 - 0xa0];
    void* archive;
    char pad1A4[0x568 - 0x1a4];
};

extern "C" {
extern char lbl_71_data_0[];
Ground* fn_71_2628(int, const char*, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);

void fn_71_1358(Stage* self, int kind) {
    Ground* ground;
    const char* data = lbl_71_data_0;
    switch (kind) {
    case 11:
        ground = fn_71_2628(31, data + 0x2b4, data + 0x2c4);
        break;
    case 12:
        ground = fn_71_2628(32, data + 0x2dc, data + 0x2ec);
        break;
    default:
        ground = 0;
        break;
    }
    if (ground) {
        addGround__5StageFP6Ground(self, ground);
        ground->startup(self->archive, 0, 0);
        ground->setValue(self->value);
    }
}
}
