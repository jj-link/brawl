#pragma force_active on
extern "C" {
void* GetResAnmScn__Q34nw4r3g3d7ResFileFi(void*, int);
void fn_801971D0(void*, void*);
void fn_8000D6DC(void*, void*);
extern void* g_gfSceneRoot;

void fn_25_97C(unsigned char* self) {
    if (self[0x7c] != 1) {
        void* anm = GetResAnmScn__Q34nw4r3g3d7ResFileFi(self + 0x54, 0);
        *(void**)(self + 0x68) = anm;
        void* tmp = anm;
        fn_801971D0(self + 0x68, &tmp);
        fn_8000D6DC(g_gfSceneRoot, self + 0x68);
        self[0x7c] = 1;
    }
}
}
