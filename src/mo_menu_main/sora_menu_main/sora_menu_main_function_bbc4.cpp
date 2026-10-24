#pragma force_active on
extern "C" {
int isReady__14gfFileIOHandleCFv(const void*);
int isLoadFinish__20tyFigListDataManagerFv(void*);
int getReturnStatus__14gfFileIOHandleCFv(const void*);
void* getBuffer__14gfFileIOHandleCFv(const void*);
void release__14gfFileIOHandleFv(void*);
void Init__Q34nw4r3g3d7ResFileFPv(void*);
void* GetResAnmScn__Q34nw4r3g3d7ResFileFi(void*, int);
void fn_801971D0(void*, void*);
void fn_1_6FD0(int, void*);
void fn_1_6E30(int);
void fn_1_6DA0(int, int);
void fn_2_8F7C(void*);
void fn_2_9460(void*, int, void*);
void fn_2_9708(void*);
void fn_800B330C(int, void*, int);
void endKeepScreen__17gfKeepFrameBufferFv(void*);
extern char* g_gfApplication;
extern char lbl_2_data_127C[];
}

extern "C" int fn_2_BBC4(void* arg0) {
    char* self = (char*)arg0;
    void* buf;
    int i = 0;
    char* h = self + 0x264;
    do {
        if (!isReady__14gfFileIOHandleCFv(h)) {
            return 0;
        }
        i++;
        h += 4;
    } while (i < 11);

    if (!isLoadFinish__20tyFigListDataManagerFv(*(void**)(self + 0xD8))) {
        return 0;
    }
    if (!isReady__14gfFileIOHandleCFv(self + 0x290)) {
        return 0;
    }

    void* sp10;
    void* spC;
    int sp8;
    fn_2_8F7C(self);
    sp8 = 0;
    buf = 0;
    fn_1_6E30(*(int*)(self + 0x40));
    spC = buf;
    if (getReturnStatus__14gfFileIOHandleCFv(self + 0x280) == 0x15) {
        buf = 0;
    } else {
        buf = getBuffer__14gfFileIOHandleCFv(self + 0x280);
        release__14gfFileIOHandleFv(self + 0x280);
    }
    if (buf != 0) {
        spC = buf;
        Init__Q34nw4r3g3d7ResFileFPv(&spC);
    }
    *(void**)(self + 0xE4) = spC;

    void* r = GetResAnmScn__Q34nw4r3g3d7ResFileFi(self + 0xE4, 0);
    sp8 = (int)r;
    sp10 = r;
    fn_801971D0(&sp8, &sp10);
    fn_1_6FD0(*(int*)(self + 0x40), &sp8);
    fn_2_9708(self);

    int n = *(int*)(self + 0x2B8) - 1;
    if (n < 0) {
        n = 1;
    }
    *(void**)(self + 0xA0) = *(void**)(self + 0x2B0 + n * 4);
    Init__Q34nw4r3g3d7ResFileFPv(self + 0xA0);
    release__14gfFileIOHandleFv(self + 0x290);

    unsigned char* u = (unsigned char*)self;
    int cnt = 0;
    if (((u[0x4C]) >> 7) & 1) {
        cnt = 1;
    }
    if (((u[0x60]) >> 7) & 1) {
        cnt += 1;
    }
    if (((u[0x74]) >> 7) & 1) {
        cnt += 1;
    }
    if (((u[0x88]) >> 7) & 1) {
        cnt += 1;
    }
    if (cnt > 0) {
        return 1;
    }

    endKeepScreen__17gfKeepFrameBufferFv(*(char**)&g_gfApplication + 0xD0);
    fn_1_6DA0(*(int*)(self + 0x40), *(int*)(self + 0x178));
    fn_2_9460(self, *(int*)(self + 0x254), self + 0xA0);
    fn_1_6DA0(*(int*)(self + 0x40), *(int*)(self + 0x29C));

    char* p = self;
    for (int j = 0; j < 4; j++) {
        fn_800B330C(*(int*)(p + 0x108), lbl_2_data_127C, 0);
        p += 4;
    }
    return 2;
}
