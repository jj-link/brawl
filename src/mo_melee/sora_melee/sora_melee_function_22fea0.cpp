#pragma force_active on

struct GroundData {
    char padding[0x3C];
};

struct Ground : GroundData {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
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
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void cleanup();
};

struct Stage {
    char padding[0xA0];
    void* manager;
};

struct Entry {
    int state;
    int field4;
    Ground* ground;
    void* entity;
    void* resource;
    void* allocation;
};

extern "C" {
void fn_801108D0(void*, int);
extern unsigned char lbl_27_data_4B4E0[8];
extern unsigned char lbl_27_data_4B598[8];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void endEntity__8grMadeinFv(void*);
void removeGround__5StageFP6Ground(Stage*, Ground*);
void exit__6gfTaskFv(void*);
void fn_27_232374(void*, void*);
void free__13gfHeapManagerFPv(void*);

void fn_27_22FEA0(Stage* stage, Entry* entry)
{
    if (entry->entity) {
        fn_801108D0(entry->entity, 1);
        entry->entity = 0;
    }

    Ground* ground = entry->ground;
    if (ground) {
        void* madein = __dynamic_cast(
            ground, 0x3C, lbl_27_data_4B4E0, lbl_27_data_4B598, 0);
        if (madein) {
            endEntity__8grMadeinFv(madein);
        }

        removeGround__5StageFP6Ground(stage, ground);
        ground->cleanup();
        exit__6gfTaskFv(ground);
        entry->ground = 0;
    }

    if (entry->resource) {
        fn_27_232374(stage->manager, entry->resource);
        entry->resource = 0;
    }

    if (entry->allocation) {
        free__13gfHeapManagerFPv(entry->allocation);
        entry->allocation = 0;
    }

    entry->state = 0;
}
}
