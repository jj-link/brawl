#pragma force_active on
extern "C" {
void* getData__9gfArchiveF11ARCNodeTypeiUs(void*, int, int, unsigned short);
void registScnAnim__5StageFPQ34nw4r3g3d11ResFileDataUl(void*, void*, unsigned long);

void fn_27_231078(void*, void*);
}

void fn_27_231078(void* self, void* arg) {
    void* data = getData__9gfArchiveF11ARCNodeTypeiUs(
        *(void**)((char*)self + 0x1A0), 5, (int)arg, 0xFFFE);
    registScnAnim__5StageFPQ34nw4r3g3d11ResFileDataUl(self, data, 0);
}
