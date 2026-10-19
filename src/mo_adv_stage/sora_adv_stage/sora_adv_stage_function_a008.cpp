#pragma force_active on
typedef unsigned long u32;

struct Data {
    char pad[0x11];
    unsigned char model;
    unsigned char collision;
    char rest[0x1d];
    char trigger[1];
};

struct Counts {
    u32 pad;
    u32 count;
};

struct Container {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Data* get(u32);
    u32 pad;
    Counts* counts;
};

struct Ground {
    char pad[0x3c];
    virtual void v0();
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a20();
    virtual void a21();
    virtual void a22();
    virtual void a23();
    virtual void a24();
    virtual void a25();
    virtual void a26();
    virtual void a27();
    virtual void a28();
    virtual void a29();
    virtual void a30();
    virtual void a31();
    virtual void a32();
    virtual void a33();
    virtual void a34();
    virtual void a35();
    virtual void init(void*, int, int);
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual void b4();
    virtual void b5();
    virtual void b6();
    virtual void b7();
    virtual void b8();
    virtual void b9();
    virtual void b10();
    virtual void b11();
    virtual void b12();
    virtual void b13();
    virtual void b14();
    virtual void b15();
    virtual void b16();
    virtual void b17();
    virtual void b18();
    virtual void b19();
    virtual void b20();
    virtual void b21();
    virtual void b22();
    virtual void b23();
    virtual void b24();
    virtual void b25();
    virtual void b26();
    virtual void b27();
    virtual void b28();
    virtual void b29();
    virtual void b30();
    virtual void b31();
    virtual void b32();
    virtual void b33();
    virtual void b34();
    virtual void b35();
    virtual void b36();
    virtual void b37();
    virtual void b38();
    virtual void b39();
    virtual void b40();
    virtual void b41();
    virtual void set(Data*);
};

struct Stage {
    char pad[0x1a0];
    void* archive;
};

extern "C" {
extern void* g_stTriggerMng;
extern char lbl_40_data_370[];

void* createTrigger__12stTriggerMngFQ27Gimmick8AreaKindP13stTriggerData(
    void*, int, void*);
Ground* fn_40_32308(short, void*, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);
void* __nw__FUlQ25Heaps8HeapType(u32, int);
void testCollDataInit__5StageFP9gfArchiveP10grCollDataUl(
    Stage*, void*, void*, u32);
void* create__11grCollisionFP5StagePvP6Groundi(Stage*, void*, Ground*, int);
void setCollision__5StageFP11grCollision(Stage*, void*);
void __dl__FPv(void*);
Container* searchContainer__20stDataMultiContainerFUlUl(void*, u32, u32);

void fn_40_A008(Stage* stage, u32 kind, void* multi) {
    void* coll;
    u32 collision;
    Data* data;
    Ground* ground;
    Container* container;
    u32 n = 0;
    u32 i;

    while ((container = searchContainer__20stDataMultiContainerFUlUl(
                multi, kind, n++)) != 0) {
        for (i = 0; i < container->counts->count; i++) {
            data = container->get(i);
            void* trigger =
                createTrigger__12stTriggerMngFQ27Gimmick8AreaKindP13stTriggerData(
                    g_stTriggerMng, 2, data->trigger);
            ground = fn_40_32308(
                (short)data->model, (char*)trigger + 0x2c, lbl_40_data_370);
            if (ground) {
                addGround__5StageFP6Ground(stage, ground);
                ground->set(data);
                ground->init(stage->archive, 0, 0);
                collision = data->collision;
                if (collision != 255) {
                    coll = __nw__FUlQ25Heaps8HeapType(0x28, 15);
                    if (coll) {
                        testCollDataInit__5StageFP9gfArchiveP10grCollDataUl(
                            stage, stage->archive, coll, collision);
                        void* result =
                            create__11grCollisionFP5StagePvP6Groundi(
                                stage, coll, ground, 1);
                        setCollision__5StageFP11grCollision(stage, result);
                    }
                    __dl__FPv(coll);
                }
            }
        }
    }
}
}
