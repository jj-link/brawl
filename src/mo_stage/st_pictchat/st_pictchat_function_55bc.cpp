#pragma force_active on
struct Base { char pad[0x3c]; };
struct Self : Base {
    virtual void v0();virtual void v1();virtual void v2();virtual void v3();virtual void v4();virtual void v5();virtual void v6();virtual void v7();virtual void v8();virtual void v9();
    virtual void v10();virtual void v11();virtual void v12();virtual void v13();virtual void v14();virtual void v15();virtual void v16();virtual void v17();virtual void v18();virtual void v19();
    virtual void v20();virtual void v21();virtual void v22();virtual void v23();virtual void v24();virtual void v25();virtual void v26();virtual void v27();virtual void v28();virtual void v29();
    virtual void v30();virtual void v31();virtual void v32();virtual void v33();virtual void v34();virtual void v35();virtual void v36();virtual void v37();virtual void v38();virtual void v39();
    virtual void v40();virtual void v41();virtual void v42();virtual void v43();virtual void v44();virtual void v45();virtual void v46();virtual void v47();
    virtual void vf(char* p, unsigned long a, unsigned long b);
    char pad1[0x110];
    unsigned char kind;
    char pad2[7];
    char* data;
    char pad3[0x120];
    char* flags;
    unsigned char state;
    char pad4[0x1b];
    unsigned long vals[6];
};
extern "C" void fn_73_55BC(Self* s) {
    if (s->state == 1) {
        if (s->data) {
            s->vf(s->data + 0x114, 0, s->vals[0]);
            s->vf(s->data + 0x120, 0, s->vals[1]);
            s->vf(s->data + 0x12c, 0, s->vals[2]);
            s->vf(s->data + 0x138, 0, s->vals[3]);
            s->vf(s->data + 0x144, 0, s->vals[4]);
            s->vf(s->data + 0x150, 0, s->vals[5]);
        }
        switch (s->kind) {
        case 3:
            if (s->flags) {
                s->flags[0] = 4; s->flags[1] = 4; s->flags[2] = 4;
                s->flags[3] = 4; s->flags[4] = 4; s->flags[5] = 4;
            }
            break;
        default:
            break;
        }
    } else {
        s->state = 1;
    }
}