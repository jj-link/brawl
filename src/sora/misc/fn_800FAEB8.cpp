#pragma force_active on
extern "C" {

void startKeepScreen__17gfKeepFrameBufferFv(void*);
void fn_8000D7B8(void*);
int isReady__14gfFileIOHandleCFv(const void*);
void* getBuffer__14gfFileIOHandleCFv(const void*);
void free__13gfHeapManagerFPv(void*);
void cancelRequest__14gfFileIOHandleFv(void*);
void release__14gfFileIOHandleFv(void*);
void __dt__14gfFileIOHandleFv(void*, int);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);
void removeExist__6utListFP10utListNode(void*, void*);

extern char lbl_8045C41C[];
extern char lbl_8045C4BC[];
extern char lbl_8045B4B8[];
extern char lbl_8049E550[];
extern char* g_gfApplication;
extern char* g_gfSceneRoot;

void* fn_800FAEB8(void* self, int arg1) {
    char* s = (char*)self;
    if (s != 0) {
        *(void**)(s + 0x3C) = lbl_8045C41C;
        if (((*(unsigned char*)(s + 0x42) >> 5) & 1) != 0) {
            startKeepScreen__17gfKeepFrameBufferFv(g_gfApplication + 0xD0);
        }
        fn_8000D7B8(g_gfSceneRoot);
        if ((void*)(s + 0x48) != 0) {
            *(void**)(s + 0x78) = lbl_8045C4BC;
            *(char**)(s + 0x58) = (char*)lbl_8045C4BC + 8;
            if (*(unsigned char*)(s + 0x70) != 0) {
                if (isReady__14gfFileIOHandleCFv(s + 0x6C)) {
                    void* buf = getBuffer__14gfFileIOHandleCFv(s + 0x6C);
                    free__13gfHeapManagerFPv(buf);
                } else {
                    cancelRequest__14gfFileIOHandleFv(s + 0x6C);
                }
                release__14gfFileIOHandleFv(s + 0x6C);
                *(unsigned char*)(s + 0x70) = 0;
            }
            *(int*)(s + 0x48) = 0;
            *(signed char*)(s + 0x74) = 0;
            if ((void*)(s + 0x5C) != 0) {
                unsigned char flag70_2 = *(unsigned char*)(s + 0x70);
                *(void**)(s + 0x68) = lbl_8045B4B8;
                if (flag70_2) {
                    if (isReady__14gfFileIOHandleCFv(s + 0x6C)) {
                        void* buf = getBuffer__14gfFileIOHandleCFv(s + 0x6C);
                        free__13gfHeapManagerFPv(buf);
                    } else {
                        cancelRequest__14gfFileIOHandleFv(s + 0x6C);
                    }
                    release__14gfFileIOHandleFv(s + 0x6C);
                    *(unsigned char*)(s + 0x70) = 0;
                }
                release__14gfFileIOHandleFv(s + 0x6C);
                __dt__14gfFileIOHandleFv(s + 0x6C, -1);
                if ((void*)(s + 0x5C) != 0) {
                    if ((void*)(s + 0x5C) != 0) {
                        removeExist__6utListFP10utListNode(lbl_8049E550, s + 0x5C);
                        *(void**)(s + 0x64) = 0;
                        if ((void*)(s + 0x5C) != 0) {
                            if (*(void**)(s + 0x64) != 0) {
                                removeExist__6utListFP10utListNode(0, s + 0x5C);
                                *(void**)(s + 0x64) = 0;
                            }
                        }
                    }
                }
            }
            if ((void*)(s + 0x4C) != 0) {
                if ((void*)(s + 0x4C) != 0) {
                    removeExist__6utListFP10utListNode(lbl_8049E550, s + 0x4C);
                    *(void**)(s + 0x54) = 0;
                    if ((void*)(s + 0x4C) != 0) {
                        if (*(void**)(s + 0x54) != 0) {
                            removeExist__6utListFP10utListNode(0, s + 0x4C);
                            *(void**)(s + 0x54) = 0;
                        }
                    }
                }
            }
        }
        __dt__6gfTaskFv(s, 0);
        if (arg1 > 0) {
            __dl__FPv(s);
        }
    }
    return self;
}

}
