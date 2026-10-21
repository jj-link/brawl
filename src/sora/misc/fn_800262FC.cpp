#pragma force_active on
extern "C" {

struct FTSys {
    int unk0;
    int unk4;
};

extern FTSys lbl_805A0030;
void fn_80026420();
void fn_8002646C();

void fn_800262FC(void* p1, unsigned int p2, unsigned int p3) {
    lbl_805A0030.unk0 = (int)&fn_80026420;
    lbl_805A0030.unk4 = (int)&fn_8002646C;
    *(int*)((char*)p1 + 0x40) = (int)&lbl_805A0030;
    *(int*)((char*)p1 + 0x44) = (int)p1;
    *(int*)((char*)p1 + 0x48) = p2;
    *(int*)((char*)p1 + 0x4C) = p3;
}

}
