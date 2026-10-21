#pragma force_active on
#pragma opt_propagation off

struct ItemEntry {
    int unused;
    int kind;
    unsigned int archive;
};

struct StageData {
    void* initial;
    char padding[0x3FC];
    ItemEntry items[16];
    char name[1];
};

extern "C" StageData lbl_89_data_0;
extern "C" char lbl_89_data_8E0[];

extern "C" void __ct__7stMeleeFPCcQ26Stages11srStageKind(void*, const char*, int);
extern "C" void* getInstance__9itManagerFv();
extern "C" void* preloadItemKindArchive__9itManagerF6itKindUlQ29itArchive4Typeb(
    void*, int, unsigned int, int, int);
extern "C" void setPlayerPositionIndexSerial__7stMeleeFv(void*);

extern "C" void* fn_89_A4(void* self) {
    StageData* base = &lbl_89_data_0;
    ItemEntry* p;
    int i;

    __ct__7stMeleeFPCcQ26Stages11srStageKind(self, base->name, 0x38);
    *(void**)((char*)self + 0x3C) = lbl_89_data_8E0;
    p = base->items;
    *(void**)((char*)self + 0x35C) = base->initial;
    *(int*)((char*)self + 0x360) = 0;
    i = 0;

    do {
        preloadItemKindArchive__9itManagerF6itKindUlQ29itArchive4Typeb(
            getInstance__9itManagerFv(), p->kind, p->archive, 0, 1);
        i += 1;
        p++;
    } while (i < 0x10);

    *(int*)((char*)self + 0x2F8) = 0;
    *(int*)((char*)self + 0x2FC) = 0;
    *(int*)((char*)self + 0x300) = 0;
    *(int*)((char*)self + 0x304) = 0;
    *(int*)((char*)self + 0x33C) = 0;
    *(int*)((char*)self + 0x348) = 0;
    setPlayerPositionIndexSerial__7stMeleeFv(self);
    return self;
}
