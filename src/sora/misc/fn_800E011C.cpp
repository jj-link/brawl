#pragma force_active on

extern "C" void fn_800E1384(void*);
extern "C" void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
extern "C" void cancelRequest__14gfFileIOHandleFv(void*);
extern "C" void free__13gfHeapManagerFPv(void*);
extern "C" void fn_800257B0(int, int);
extern "C" void OSReport(const char*, ...);
extern char lbl_8045A2EC[];

struct Base {
    char pad[0x5C];
};

struct Entry : Base {
    virtual void f2(int);
};

extern "C" void fn_800E011C(char* self) {
    fn_800E1384(self);

    char* q = self;
    for (int i = 0; i < 3; i++) {
        void* p = *(void**)(q + 0xF0);
        if (p != 0) {
            Destroy__Q34nw4r3g3d6G3dObjFv(p);
            *(void**)(q + 0xF0) = 0;
        }
        q += 4;
    }

    q = self;
    for (int i = 0; i < 0x32; i++) {
        Entry* e = *(Entry**)(q + 0x28);
        if (e != 0) {
            if (e != 0) {
                e->f2(1);
            }
            *(void**)(q + 0x28) = 0;
        }
        q += 4;
    }

    cancelRequest__14gfFileIOHandleFv(self + 0x290);

    void* b = *(void**)(self + 0x2A4);
    if (b != 0) {
        free__13gfHeapManagerFPv(b);
        *(void**)(self + 0x2A4) = 0;
        *(void**)(self + 0x294) = 0;
    }

    void* c = *(void**)(self + 0x2B8);
    *(int*)(self + 0x298) = -1;
    if (c != 0) {
        free__13gfHeapManagerFPv(c);
        *(void**)(self + 0x2B8) = 0;
        OSReport(lbl_8045A2EC, *(int*)(self + 0x2B4));
        fn_800257B0((unsigned char)*(int*)(self + 0x2B4), 0);
    }
}
