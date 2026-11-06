#pragma force_active on
extern "C" {
void* getInstance__16CameraControllerFv(void*);
void changeInput__16CameraControllerFQ216CameraController4Kind(void*, int);
int isReady__14gfFileIOHandleCFv(void*);
void* getBuffer__14gfFileIOHandleCFv(void*);
void Init__Q34nw4r3g3d7ResFileFPv(void*);
void release__14gfFileIOHandleFv(void*);
void playBGM__9sndSystemFiUlb(void*, int, unsigned long, int);
void endKeepScreen__17gfKeepFrameBufferFv(void*);
void fn_4_7928(void*, void*);
extern void* g_sndSystem;
extern char* g_gfApplication;
extern void* lbl_805A01D8;
}

extern "C" void fn_4_8B84(void* arg0) {
    char* self = (char*)arg0;
    char* p30;
    int* p29;
    char* p28;
    unsigned int idx;
    void* lbl;

    if (*(unsigned char*)(self + 0x1393) == 0) {
        void* obj = *(void**)(self + 0x40);
        if (*(unsigned char*)((char*)obj + 0x1A4) == 0) {
            return;
        }
        changeInput__16CameraControllerFQ216CameraController4Kind(getInstance__16CameraControllerFv(obj), 9);
        *(unsigned char*)(self + 0x1393) = 1;
    }

    p30 = self;
    p29 = (int*)(self + 0x1394);
    idx = 0;
    do {
        p28 = self + idx;
        if (*(unsigned char*)(p28 + 0x1390) == 0 && *(int*)(p30 + 0x1394) != 0) {
            if (isReady__14gfFileIOHandleCFv(p29) == 0) {
                return;
            }
            *(unsigned char*)(p28 + 0x1390) = 1;
        }
        p30 += 4;
        idx++;
        p29++;
    } while (idx < 3);

    *(void**)(self + 0x1210) = getBuffer__14gfFileIOHandleCFv(self + 0x1398);
    Init__Q34nw4r3g3d7ResFileFPv(self + 0x1210);
    release__14gfFileIOHandleFv(self + 0x1398);

    *(void**)(self + 0x1214) = getBuffer__14gfFileIOHandleCFv(self + 0x139C);
    Init__Q34nw4r3g3d7ResFileFPv(self + 0x1214);
    release__14gfFileIOHandleFv(self + 0x139C);

    *(unsigned char*)(self + 0x13A0) = 1;
    playBGM__9sndSystemFiUlb(g_sndSystem, 0x2701, 0, 1);
    lbl = lbl_805A01D8;
    *(int*)((char*)lbl + 0x174) = 0x2D;
    fn_4_7928(arg0, lbl);
    endKeepScreen__17gfKeepFrameBufferFv(g_gfApplication + 0xD0);
}
