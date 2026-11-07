#pragma force_active on
#pragma push
#pragma opt_propagation off

struct Base {
    char pad[0x3c];
};

class Obj : public Base {
public:
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
    virtual void v51(char*, int, char*);

    char pad1[0x158 - 0x40];
    int f158;
    char* f15c;
};

extern "C" void fn_51_3C88(void*);

extern "C" void fn_51_11A10(Obj* self) {
    fn_51_3C88(self);
    if (self->f158) {
        self->v51(self->f15c, 0, (char*)"L12LstartN");
        self->v51(self->f15c + 0xC, 0, (char*)"L12LendN");
        self->v51(self->f15c + 0x18, 0, (char*)"L12RstartN");
        self->v51(self->f15c + 0x24, 0, (char*)"L12RendN");
    }
}

#pragma pop
