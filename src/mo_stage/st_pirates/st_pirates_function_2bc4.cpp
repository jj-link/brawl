#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

extern "C" {
extern const float lbl_52_rodata_1C;
extern void* g_gfSceneRoot;
void* getData__9gfArchiveF11ARCNodeTypeiUs(void* arch, int type, int index, u16 n);
void registScnAnim__5StageFPQ34nw4r3g3d11ResFileDataUl(void* self, void* data, unsigned long n);
void setCurrentFrame__11gfSceneRootFf(void* root, float frame);
}

extern "C" void fn_52_2BC4(u8* self) {
    if (self[0x1e0] == 0) return;
    
    u8 val = self[0x55c];
    switch (val) {
        case 3: self[0x55c] = 1; break;
        case 4: self[0x55c] = 2; break;
        case 5: self[0x55c] = 0; break;
        case 6: self[0x55c] = 2; break;
        case 7: self[0x55c] = 0; break;
        case 8: self[0x55c] = 1; break;
        default: return;
    }
    
    void* arch = *(void**)(self + 0x1a0);
    void* data = getData__9gfArchiveF11ARCNodeTypeiUs(arch, 5, 0, (u16)0xFFFE);
    registScnAnim__5StageFPQ34nw4r3g3d11ResFileDataUl(self, data, self[0x55c]);
    setCurrentFrame__11gfSceneRootFf(g_gfSceneRoot, lbl_52_rodata_1C - *(float*)(self + 0x1dc));
}
