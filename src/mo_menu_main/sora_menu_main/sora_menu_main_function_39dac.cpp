#pragma force_active on
extern "C" {
class MuObject;
void changeNodeAnimN__8MuObjectFPCc(void* obj, const char* name);
void setFrameNode__8MuObjectFf(void* obj, float frame);
void playSE__9sndSystemF5SndIDiiii(void* snd, int id, int a, int b, int c, int d);
extern void* g_sndSystem;
extern const char lbl_2_data_4C08[];
extern const float lbl_2_rodata_1750;
extern const float lbl_2_rodata_1760;

class VirtBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(float f);
};

void fn_2_39DAC(char* self) {
    void* obj = *(void**)(self + 0x44);
    changeNodeAnimN__8MuObjectFPCc(obj, lbl_2_data_4C08);
    setFrameNode__8MuObjectFf(obj, lbl_2_rodata_1750);
    void* anim = *(void**)((char*)obj + 0x14);
    void* sub = *(void**)((char*)anim + 0xc);
    ((VirtBase*)sub)->v8(lbl_2_rodata_1760);
    playSE__9sndSystemF5SndIDiiii(g_sndSystem, 6, -1, 0, 0, -1);
}
}
