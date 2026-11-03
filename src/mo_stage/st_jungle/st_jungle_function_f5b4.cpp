#pragma force_active on
#pragma push
#pragma opt_propagation off

struct Ground_base {
    char pad[0x3c];
};

class Ground : public Ground_base {
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
    virtual void v49(char*, int, char*);
    virtual void v50();

    char pad1[0x15c - 0x40];
    char* field15c;
    char* field160;
};

struct Data5370 {
    char m0;
    char pad0[11];
    char mC;
    char pad1[11];
    char m18;
    char pad2[15];
};

extern Data5370 lbl_51_data_5370;
extern "C" void fn_51_3C88(void*);

extern "C" void fn_51_F5B4(Ground* self) {
    Data5370* data = &lbl_51_data_5370;
    char (Data5370::*ptr0) = &Data5370::m0;
    char (Data5370::*ptrC) = &Data5370::mC;
    char (Data5370::*ptr18) = &Data5370::m18;

    fn_51_3C88(self);

    if (self->field15c) {
        char* a = &(data->*ptr0);
        self->v49(self->field15c, 0, (char*)"L7move1N");
        char* b = &(data->*ptrC);
        self->v49(self->field15c + 0xC, 0, (char*)"L7move2N");
    }

    if (self->field160) {
        char* c = &(data->*ptr18);
        self->v49(self->field160, 0, (char*)"L7Hashigo");
    }
}

#pragma pop