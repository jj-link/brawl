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
    char pad40[0x118];
    void* unk158;
    void* unk15c;
};

struct Stage {
    char pad0[0x9c];
    void* value;
    char padA0[0x100];
    void* archive;
    char pad1A4[0xb4];
    void* unk258;
    char pad25C[0x88];
    void* unk2e4;
};

extern "C" {
extern Ground* fn_71_27C4(int, const char*, const char*);
extern void addGround__5StageFP6Ground(Stage*, Ground*);
extern char lbl_71_data_1B8[];
extern char lbl_71_data_1D0[];

void fn_71_C78(Stage* self, int kind) {
    Ground* ground;
    switch (kind) {
    case 8:
        ground = fn_71_27C4(9, lbl_71_data_1B8, lbl_71_data_1D0);
        break;
    default:
        ground = 0;
        break;
    }
    if (ground) {
        addGround__5StageFP6Ground(self, ground);
        ground->v37(self->archive, 0, 0);
        ground->v39(self->value);
        ground->unk158 = &self->unk258;
        ground->unk15c = &self->unk2e4;
    }
}
}
