#pragma force_active on

typedef unsigned char u8;

extern "C" {
float randf__Fv();
extern const float lbl_46_rodata_138;
extern const float lbl_46_rodata_13C;
}

struct Padding {
    char pad[0x3c];
};

class Stage : public Padding {
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
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void setFrame(int, float);
    virtual float getFrame(int);

    char pad40[0x110];
    u8 state;
    char pad151[0x17];
    u8 flag;
};

extern "C" void fn_46_6574(Stage* self) {
    switch ((int)self->state) {
    case 0:
        self->state = 1;
        break;
    case 1:
        if (self->flag == 1) {
            float f = lbl_46_rodata_13C * randf__Fv();
            float r = self->getFrame(0);
            float t = lbl_46_rodata_138 * r;
            float result = t + f;
            self->setFrame(0, result);
        }
        self->state = 3;
        break;
    case 2:
        return;
    case 3:
        break;
    }
}
