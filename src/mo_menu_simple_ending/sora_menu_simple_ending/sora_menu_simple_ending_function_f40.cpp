#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

extern "C" {
extern void* g_GameGlobal;
extern void* g_gfSceneRoot;

struct Floats {
    float a, b, c, d, e;
};
extern const Floats lbl_19_rodata_20;
extern char lbl_19_data_4AC[];
extern char lbl_19_data_4C4[];

void* getGlobalRecordMenuDatap__10GameGlobalFv(void*);
void* getData__9gfArchiveF11ARCNodeTypeiUs(void*, int, int, u16);
void Init__Q34nw4r3g3d7ResFileFPv(void*);
void* GetResAnmScn__Q34nw4r3g3d7ResFileFi(void*, int);
void fn_801971D0(void*, void*);
void fn_8000D6DC(void*, void*);
void* create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(
    void*, const char*, int, void*, int);
void* fn_800B6AC0(void*, const char*);
void fn_80192ECC(void*, float, float, float);
void fn_8007F2B4(void*, void*, int);
void fn_8007F148(void*);
void fn_8007EF70(void*, int, int, int, int);
}

struct Object {
    char pad[0x10];
    void* scene;
};

struct State {
    char pad[0x40];
    void* file;
    void* other;
    Object* object;
    char pad2[0x960];
    void* manager;
};

extern "C" void fn_19_F40(State* s, void* archive) {
    const Floats* values = &lbl_19_rodata_20;
    struct Record {
        char pad[0x28];
        unsigned char flag : 1;
    };

    bool mode =
        ((Record*)getGlobalRecordMenuDatap__10GameGlobalFv(g_GameGlobal))->flag;

    s->file = getData__9gfArchiveF11ARCNodeTypeiUs(
        archive, 2, mode, (u16)0xFFFE);
    s->other = getData__9gfArchiveF11ARCNodeTypeiUs(
        archive, 2, 2, (u16)0xFFFE);

    Init__Q34nw4r3g3d7ResFileFPv(&s->file);
    Init__Q34nw4r3g3d7ResFileFPv(&s->other);

    void* anm = 0;
    void* node;
    anm = GetResAnmScn__Q34nw4r3g3d7ResFileFi(&s->file, 0);
    void* tmp = anm;
    fn_801971D0(&anm, &tmp);
    fn_8000D6DC(g_gfSceneRoot, &anm);

    s->object =
        (Object*)create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(
            &s->other, lbl_19_data_4AC, 1, 0, 42);
    node = fn_800B6AC0(s->object, lbl_19_data_4C4);

    if (!mode)
        fn_80192ECC(&node, values->a, values->b, values->c);
    else
        fn_80192ECC(&node, values->d, values->e, values->c);

    fn_8007F2B4(s->manager, s->object->scene, 0);
    fn_8007F148(s->manager);
    fn_8007EF70(s->manager, 0, 0, -1, -1);
}
