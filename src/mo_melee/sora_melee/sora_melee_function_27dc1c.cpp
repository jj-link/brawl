#pragma force_active on

struct Module {
    char pad[0x3C];
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
    virtual int check();
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
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void action();
};

struct PlayerData {
    unsigned char index;
    char pad[0x5B];
};

struct Data {
    char pad00[0xB];
    unsigned char flags;
    char pad0C[0xB];
    signed char value;
    char pad18[0x82];
    PlayerData players[1];
};

struct Object {
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
    virtual int check();
    char pad04[8];
    Data* data;
    char pad10[0x20];
    Module* module;
    unsigned char flags;
    char pad35[3];
    unsigned int id;
};

struct IfManager {
    char pad[0x4C];
    void* entries[1];
};

struct ftManager;

extern "C" {
extern ftManager* g_ftManager;
extern IfManager* g_IfMngr;
extern Module* lbl_27_bss_5668;

int getPlayerNo__9ftManagerFi(ftManager*, int);
void fn_800E3388(void*, int);

void fn_27_27DC1C(Object* self, unsigned int id) {
    if (self->check() && ((self->flags >> 5) & 1) &&
        (!self->module || !self->module->check())) {
        int player = getPlayerNo__9ftManagerFi(g_ftManager, id);
        IfManager* manager = g_IfMngr;
        if (manager) {
            Data* data = self->data;
            if ((data->flags >> 2) & 1) {
                fn_800E3388(manager->entries[data->players[player].index],
                           data->value);
            }
        }
        Module* module = lbl_27_bss_5668;
        if (module && self->id == id) {
            module->action();
        }
    }
}
}
