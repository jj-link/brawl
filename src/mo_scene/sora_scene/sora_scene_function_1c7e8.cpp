#pragma force_active on
extern "C" {
unsigned isReady__14gfFileIOHandleCFv(void*);
void* getBuffer__14gfFileIOHandleCFv(void*);
void Init__Q34nw4r3g3d7ResFileFPv(void*);
void* GetResAnmScn__Q34nw4r3g3d7ResFileFi(void*, int);
void fn_801971D0(void*, void*);
void fn_8000D6DC(void*, void*);
void fn_80073F84(void*, int);
int fn_800BA3D8(void*);
int fn_1_1CAC0(void*);
void OSReport(const char*, ...);
void* getInstance__14gfSceneManagerFv();
extern void* g_gfSceneRoot;
extern void* g_sndSystem;
extern char lbl_1_data_5FF0[];
extern char lbl_1_data_6000[];
}

struct Obj {
    char pad[0x40];
    int s40;
    char pad2[8];
    int s4C;
    char pad3[0xBC];
    int f10C, f110, f114, f118;
    char pad4[0x124 - 0x11C];
    unsigned char f124;
    char pad5[0x338 - 0x125];
    int f338, f33C;
    char pad6[0x352 - 0x340];
    char f352, f353;
};

struct Sub {
    int a0, a4, a8, aC;
    unsigned char b0;
    unsigned char b1;
};

struct Self {
    int p0, p4;
    Obj* obj;
    int pC;
    Sub* sub;
    char io[4];
    void* buf;
    int state;
};

extern "C" int fn_1_1C7E8(Self* self) {
    int flag = 0;
    int res = (int)self;
    switch (self->state) {
    case 0:
        self->state = 1;
        return 0;
    case 1:
        if (isReady__14gfFileIOHandleCFv(&self->io) == 1) self->state = 2;
        return 0;
    case 2: {
        fn_80073F84(g_sndSystem, 0x1e);
        self->buf = getBuffer__14gfFileIOHandleCFv(&self->io);
        Init__Q34nw4r3g3d7ResFileFPv(&self->buf);
        void* spC = 0;
        void* sp8;
        spC = GetResAnmScn__Q34nw4r3g3d7ResFileFi(&self->buf, 0);
        sp8 = spC;
        fn_801971D0(&spC, &sp8);
        fn_8000D6DC(g_gfSceneRoot, &spC);
        self->state = 3;
        return 0;
    }
    case 4:
        return 0;
    default: {
        Obj* o = self->obj;
        if (o == 0) return 0;
        switch (o->s40) {
        case 0:
            break;
        case 2:
            flag = 1;
            if (o->s4C == 1) {
                res = 2;
                self->sub->a0 = 0;
                self->sub->b1 = 0;
            } else {
                Sub* s = self->sub;
                if (s) {
                    if (o->f114 != 0 || o->f10C != 0) s->a0 = o->f338 + 1;
                    else s->a0 = 0;
                    self->sub->b1 = self->obj->f124;
                    s = self->sub;
                    if (s->b1 != 0) {
                        Obj* p = self->obj;
                        if (p->f118 != 0 || p->f110 != 0) s->a4 = p->f33C + 1;
                        else s->a4 = 0;
                        self->sub->aC = fn_800BA3D8((char*)self->obj + 0x228);
                    } else {
                        s->a4 = -1;
                        self->sub->aC = -1;
                    }
                }
                res = 1;
            }
            break;
        case 3:
            flag = 1;
            res = 0;
            if (self->sub) {
                self->sub->a0 = 0;
                self->sub->b1 = 0;
            }
            break;
        case 1: {
            int r = fn_1_1CAC0(self);
            if (self->pC == 0) {
                if (r != 0) {
                    Obj* q = self->obj;
                    q->f352 = 1;
                    q->f353 = 1;
                    OSReport(lbl_1_data_5FF0);
                } else {
                    Obj* q = self->obj;
                    q->f352 = 1;
                    q->f353 = 0;
                    OSReport(lbl_1_data_6000);
                }
            }
            break;
        }
        }
        if (flag != 0) {
            char* m = (char*)getInstance__14gfSceneManagerFv();
            *(int*)(m + 0x284) = res;
            *(int*)(m + 0x288) = 2;
        }
        return 0;
    }
    }
}
