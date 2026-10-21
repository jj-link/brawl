#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;

struct Vec {
    float x, y, z;
};

struct StageBase {
    char pad0[0x3c];
};

class Stage : public StageBase {
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
    virtual void getPosition(Vec*, int, u32);

    char pad1[0x114];
    Vec* positions;
    u8 initialized;
    char pad2[0x1f];
    float x[6][5];
    char pad3[0x20];
    u32 ids[6][5];
};

extern "C" const float lbl_79_rodata_14;

extern "C" void fn_79_20F0(Stage* self) {
    if (self->initialized != 1) {
        for (u8 i = 0; i < 6; ++i) {
            for (u8 j = 0; j < 5; ++j) {
                Vec pos;
                self->getPosition(&pos, 0, self->ids[i][j]);
                pos.y += lbl_79_rodata_14;
                self->positions[i * 5 + j] = pos;
                self->x[i][j] = pos.x;
            }
        }
        self->initialized = 1;
    }
}
