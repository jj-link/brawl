#pragma force_active on

struct gfHeapManager;

struct gfTask {
    char pad0[0x4C];
    void* unk4C;
    void* unk50;
    void* unk54;
    char pad58[0x18];
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7C;
    short unk80;
    short unk82;
    void* unk84;
    short unk88;
    short unk8A;
    void* unk8C;
    short unk90;
    char pad92[0xA];
    void* unk9C;
    unsigned short unkA0;
    short unkA2;
    char padA4[8];
    void* unkAC;
    unsigned short unkB0;
    short unkB2;
    int unkB4;
};

struct TaskEntry {
    char pad[0x88];
    void* unk88;
    char pad2[0x18];
};

extern "C" {
void exit__6gfTaskFv(gfTask*);
void* fn_803CCEBC();
void free__13gfHeapManagerFPv(void*);
}

extern gfTask* lbl_805A0088;

extern "C" void fn_8003354C(void) {
    gfTask* self = lbl_805A0088;
    if (self != 0) {
        if (self->unk9C != 0) {
            unsigned short i = 0;
            while (i < self->unkA0) {
                TaskEntry* e = (TaskEntry*)((char*)self->unk9C + i * 0xA0);
                if (e->unk88 != 0) free__13gfHeapManagerFPv(e->unk88);
                i++;
            }
            free__13gfHeapManagerFPv(self->unk9C);
            self->unk9C = 0;
        }
        self->unkA0 = 0;
        self->unkA2 = 0;
        if (self->unkAC != 0) {
            unsigned short i = 0;
            while (i < self->unkB0) {
                TaskEntry* e = (TaskEntry*)((char*)self->unkAC + i * 0xA0);
                if (e->unk88 != 0) free__13gfHeapManagerFPv(e->unk88);
                i++;
            }
            free__13gfHeapManagerFPv(self->unkAC);
            self->unkAC = 0;
        }
        self->unkB0 = 0;
        self->unkB2 = 0;
        if (&self->unk7C != 0) {
            if (self->unk7C != 0) {
                free__13gfHeapManagerFPv(self->unk7C);
                self->unk7C = 0;
            }
            self->unk80 = 0;
            self->unk82 = 0;
        }
        if (&self->unk84 != 0) {
            if (self->unk84 != 0) {
                free__13gfHeapManagerFPv(self->unk84);
                self->unk84 = 0;
            }
            self->unk88 = 0;
            self->unk8A = 0;
        }
        if (&self->unk8C != 0) {
            if (self->unk8C != 0) {
                free__13gfHeapManagerFPv(self->unk8C);
                self->unk8C = 0;
            }
            self->unk90 = 0;
        }
        fn_803CCEBC();
        if (self->unk54 != 0) {
            free__13gfHeapManagerFPv(self->unk54);
            self->unk54 = 0;
        }
        if (self->unk50 != 0) {
            free__13gfHeapManagerFPv(self->unk50);
            self->unk50 = 0;
        }
        if (self->unk4C != 0) {
            free__13gfHeapManagerFPv(self->unk4C);
            self->unk4C = 0;
        }
        self->unkB4 = 4;
        free__13gfHeapManagerFPv(self->unk70);
        free__13gfHeapManagerFPv(self->unk74);
        free__13gfHeapManagerFPv(self->unk78);
        exit__6gfTaskFv(lbl_805A0088);
        lbl_805A0088 = 0;
    }
}
