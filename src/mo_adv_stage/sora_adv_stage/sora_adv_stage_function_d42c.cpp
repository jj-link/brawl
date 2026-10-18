#pragma force_active on
typedef unsigned long u32;

struct Entry {
    unsigned char pad[0xcc];
    unsigned char type;
};

struct Count {
    u32 pad;
    u32 count;
};

struct Container {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Entry* get(u32);

    u32 pad;
    Count* data;
};

struct Ground {
    unsigned char pad[0x3c];

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
    virtual void init(void*, int, int);
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
    virtual void set(Entry*);
};

struct Stage {
    unsigned char pad[0x1a0];
    void* resource;
};

struct stDataMultiContainer;

extern "C" {
extern char lbl_40_data_90[];

Ground* fn_40_1A610(short, int, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);
Container* searchContainer__20stDataMultiContainerFUlUl(
    stDataMultiContainer*, u32, u32);

void fn_40_D42C(Stage* stage, u32 kind, stDataMultiContainer* multi)
{
    Ground* ground;
    Container* container;
    u32 n = 0;
    u32 i;
    Entry* entry;

    while ((container = searchContainer__20stDataMultiContainerFUlUl(
                multi, kind, n++)) != 0) {
        for (i = 0; i < container->data->count; ++i) {
            entry = container->get(i);
            ground = fn_40_1A610((short)entry->type, 1, lbl_40_data_90);
            if (ground) {
                addGround__5StageFP6Ground(stage, ground);
                ground->set(entry);
                ground->init(stage->resource, 0, 0);
            }
        }
    }
}
}
