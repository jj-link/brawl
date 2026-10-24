#pragma force_active on
#pragma fp_contract off

extern "C" float randf__Fv();
extern "C" const float lbl_81_rodata_D8;

struct Result {
    char pad0[0x68];
    float f68;
    char pad6C[0x90];
    float lowX;
    float highX;
    float lowY;
    float highY;
    float lowZ;
    float highZ;
    float lowW;
    float highW;
};

struct Pos {
    float f0;
    float f4;
    float f8;
    float fC;
};

struct Cam {
    unsigned char b0;
    char pad1[3];
    float f4;
    char pad8[0x20];
    float f28;
};

struct Object {
    char pad0[0x3C];
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
    virtual Result* getParams();
    char pad40[0x15C - 0x40];
    Pos* pos;
    char pad160[4];
    Cam* cam;
    unsigned char state;
    char pad169[3];
    float timerX;
    float timerY;
    float zoom;
};

extern "C" void fn_81_667C(Object* obj, float delta) {
    Result* result = obj->getParams();
    if (result == 0)
        goto exit;

    obj->timerX -= delta;
    if (obj->timerX < lbl_81_rodata_D8)
        obj->timerX = lbl_81_rodata_D8;
    obj->timerY -= delta;
    if (obj->timerY < lbl_81_rodata_D8)
        obj->timerY = lbl_81_rodata_D8;

    if (lbl_81_rodata_D8 == obj->timerX) {
        obj->zoom = result->lowX + (result->highX - result->lowX) * randf__Fv();
        obj->timerX = result->lowZ + (result->highZ - result->lowZ) * randf__Fv();
    }
    if (lbl_81_rodata_D8 == obj->timerY) {
        obj->cam->f28 = result->lowY + (result->highY - result->lowY) * randf__Fv();
        obj->cam->f28 = -obj->cam->f28;
        obj->timerY = result->lowW + (result->highW - result->lowW) * randf__Fv();
    }
    if (obj->state == 1) {
        obj->cam->f4 += obj->zoom * delta;
        if (obj->cam->f4 > obj->pos->fC + result->f68)
            obj->cam->b0 = 10;
    } else {
        obj->cam->f4 -= obj->zoom * delta;
        if (obj->cam->f4 < obj->pos->f0 - result->f68)
            obj->cam->b0 = 10;
    }
exit:;
}
