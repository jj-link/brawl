extern "C" {
unsigned char fn_27_111D70();
void fn_800DCD44(void*, unsigned char, int);
void fn_800DCD5C(void*, unsigned char, int);
void* getOwner__9ftManagerFi(void*, int);
int getPlayerNo__9ftManagerFi(void*, int);
extern void* g_ftManager;
extern void* g_IfMngr;
}

struct Obj {
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
    virtual int getFlag();
    char pad[0xC - 4];
    char* list;
};

#pragma force_active on
extern "C" void fn_27_27E140(Obj* self, int id, int arg2) {
    if (self->getFlag()) {
        int off = getPlayerNo__9ftManagerFi(g_ftManager, id) * 0x5C;
        char* e = self->list + off;
        fn_800DCD44(g_IfMngr, e[0x9a], arg2);
        getOwner__9ftManagerFi(g_ftManager, id);
        if (fn_27_111D70() == 2) {
            e = self->list + off;
            fn_800DCD5C(g_IfMngr, e[0x9a], 0);
        }
    }
}
