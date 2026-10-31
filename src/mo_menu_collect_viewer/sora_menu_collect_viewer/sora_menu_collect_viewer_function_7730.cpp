#pragma force_active on

typedef unsigned int u32;
typedef unsigned char u8;

struct CollectData {
    u8 pad0[0x1B50];
    u32 input;
    u8 pad1B54[0x1BFC - 0x1B54];
    u32 state;
    u32 previousState;
    u8 pad1C04[0x1C54 - 0x1C04];
    u8 flag1;
    u8 pad1C55[0x1C74 - 0x1C55];
    u8 flag2;
};

struct CollectBase {
    u8 pad0[0x3C];
};

struct CollectInterface : CollectBase {
    virtual void v0();   virtual void v1();
    virtual void v2();   virtual void v3();
    virtual void v4();   virtual void v5();
    virtual void v6();   virtual void v7();
    virtual void v8();   virtual void v9();
    virtual void v10();  virtual void v11();
    virtual void v12();  virtual void v13();
    virtual void v14();  virtual void v15();
    virtual void v16();  virtual void v17();
    virtual void v18();  virtual void v19();
    virtual void v20();  virtual void v21();
    virtual void v22();  virtual void v23();
    virtual void v24();  virtual void v25();
    virtual void v26();  virtual void v27();
    virtual void v28();  virtual void v29();
    virtual void v30();  virtual void v31();
    virtual void v32();  virtual void v33();
    virtual void v34();  virtual void v35();
    virtual void v36();  virtual void v37();
    virtual void v38();  virtual void v39();
    virtual void v40();  virtual void v41();
    virtual void v42();  virtual void v43();
    virtual void v44();  virtual void v45();
    virtual void v46();  virtual void v47();
    virtual void v48();  virtual void v49();
    virtual void v50();  virtual void v51();
    virtual void v52();  virtual void v53();
    virtual void v54();  virtual void v55();
    virtual void changeState(int, int);
    virtual void v59();  virtual void v60();
    virtual void v61();  virtual void v62();
    virtual void v63();  virtual void v64();
    virtual void v65();  virtual void v66();
    virtual void v67();  virtual void v68();
    virtual void v69();  virtual void v70();
    virtual void v71();
    virtual void update(int, int);
};

struct Collect : CollectInterface {
    u8 pad40[0x1A8 - 0x40];
    u32 flags;
    CollectData* data;
};

extern "C" {
extern void* g_sndSystem;
void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);

void fn_6_7730(Collect* self) {
    if (self->flags & 2) {
        if ((self->data->flag1 >> 7) & 1) {
            playSE__9sndSystemF5SndIDiiii(
                g_sndSystem, 3, -1, 0, 0, -1);
        } else {
            self->data->state = 0x1F;
            self->changeState(0xA, 1);
            playSE__9sndSystemF5SndIDiiii(
                g_sndSystem, 1, -1, 0, 0, -1);
        }
    } else if ((self->data->input & 8) || (self->flags & 4)) {
        self->data->previousState = self->data->state;
        self->data->state = 0;
        self->changeState(1, 1);
        playSE__9sndSystemF5SndIDiiii(
            g_sndSystem, (self->flags & 4) ? 2 : 0, -1, 0, 0, -1);
    } else if (self->data->input & 1) {
        self->data->state = 8;
        self->changeState(7, 1);
        playSE__9sndSystemF5SndIDiiii(
            g_sndSystem, 0, -1, 0, 0, -1);
    } else if (self->data->flag2 != 0 && (self->data->input & 2)) {
        self->data->state = 0x22;
        self->changeState(9, 1);
        playSE__9sndSystemF5SndIDiiii(
            g_sndSystem, 0, -1, 0, 0, -1);
    } else {
        self->update(0, 5);
    }
}
}
