#pragma force_active on
class gfSlowManager {
public:
    static void removeRequest(const unsigned char&);
};

inline void removeSlowRequest(const unsigned char& request) {
    unsigned char copy = request;
    gfSlowManager::removeRequest(copy);
}

extern "C" {
void* releaseArchive__15stCommonGimmickFv(void*);
void* getInstance__12gfCopyEFBMgrFv(void*);
void __dt__13grTenganEventFv(void*, int);
void __dt__14snd3DGeneratorFv(void*, int);
void __dt__7stMeleeFv(void*, int);
void __dl__FPv(void*);
extern char lbl_60_data_4D8[];
extern char* g_gfSceneRoot;
}

extern "C" void* fn_60_2A0(void* self, int arg1) {
    if (self) {
        *(void**)((char*)self + 0x3c) = lbl_60_data_4D8;
        void* inst = getInstance__12gfCopyEFBMgrFv(releaseArchive__15stCommonGimmickFv(self));
        *(unsigned char*)((char*)inst + 0x68) = 0;
        int* q = (int*)((char*)getInstance__12gfCopyEFBMgrFv(inst) + 0x6c);
        *q = 0x80;
        *(unsigned int*)(g_gfSceneRoot + 0x64) = *(unsigned int*)(g_gfSceneRoot + 0x64) & 0xFFFFFF;
        unsigned char* slow = (unsigned char*)self + 0xef1;
        if (*slow != 0xff) {
            removeSlowRequest(*slow);
        }
        __dt__13grTenganEventFv((char*)self + 0xd88, -1);
        __dt__13grTenganEventFv((char*)self + 0xcdc, -1);
        __dt__13grTenganEventFv((char*)self + 0xc30, -1);
        __dt__13grTenganEventFv((char*)self + 0xb84, -1);
        __dt__13grTenganEventFv((char*)self + 0xad8, -1);
        __dt__13grTenganEventFv((char*)self + 0xa2c, -1);
        __dt__13grTenganEventFv((char*)self + 0x980, -1);
        __dt__13grTenganEventFv((char*)self + 0x8d4, -1);
        __dt__13grTenganEventFv((char*)self + 0x828, -1);
        __dt__13grTenganEventFv((char*)self + 0x77c, -1);
        __dt__13grTenganEventFv((char*)self + 0x6d0, -1);
        __dt__13grTenganEventFv((char*)self + 0x624, -1);
        __dt__13grTenganEventFv((char*)self + 0x578, -1);
        __dt__13grTenganEventFv((char*)self + 0x4cc, -1);
        __dt__13grTenganEventFv((char*)self + 0x420, -1);
        __dt__13grTenganEventFv((char*)self + 0x374, -1);
        __dt__13grTenganEventFv((char*)self + 0x2c8, -1);
        __dt__13grTenganEventFv((char*)self + 0x21c, -1);
        __dt__14snd3DGeneratorFv((char*)self + 0x208, -1);
        __dt__7stMeleeFv(self, 0);
        if (arg1 > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
