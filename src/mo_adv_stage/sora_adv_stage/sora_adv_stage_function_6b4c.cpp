#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef float f32;
struct Base { char pad[0x3c]; };
class Stage : public Base {
public:
    virtual void processDefault(); virtual void processBegin(); virtual void fn_40_2024(); virtual void processUpdate(); virtual void processPreMapCorrection(); virtual void processMapCorrection(); virtual void processFixPosition(); virtual void processPreCollision(); virtual void processCollision(); virtual void processCatch(); virtual void processHit(); virtual void processCamera(); virtual void fn_40_21B8(); virtual void processEffect(); virtual void processGameProc(); virtual void fn_40_222C(); virtual void renderPre(); virtual void fn_40_8A84(); virtual void renderXlu(); virtual void processDebug(); virtual void renderDebug(); virtual void init(); virtual void fn_40_12F8(); virtual void fn_40_D24(); virtual void createObjPokeTrainer(); virtual void fn_40_5098(); virtual void fn_40_50A0(); virtual void fn_40_50BC(); virtual void fn_40_8B18(); virtual void fn_40_8B28(); virtual void fn_40_7D94(); virtual void fn_40_8154(); virtual void fn_40_80AC(); virtual void fn_40_8160(); virtual void fn_40_8478(); virtual void initializeStage(); virtual void closeStage(); virtual void renderDebugPositions(); virtual void fn_40_45C(); virtual void process(); virtual void fn_40_7D44();
    char pad40[0x50]; void* unk90; char pad94[0x10c]; void* archive; char pad1a4[0x380]; struct Control* control; char pad528[0x28]; u8 flag550; char pad551[15]; f32 x; f32 y; f32 z;
};
struct Control { char pad[0x604]; u8 mode; };
extern "C" void* getData__9gfArchiveF11ARCNodeTypeiUs(void*, int, int, u16);
extern "C" void createStagePositions__5StageFPQ34nw4r3g3d7ResFile(void*, void*);
extern "C" void createStagePositions__5StageFv(void*);
extern "C" void fn_27_227B68(void*, u8);
extern "C" void* lbl_805A0360;
extern "C" void fn_40_6B4C(Stage* self) {
    int index;
    if (self->control->mode == 0 || self->control->mode == 4) index = 1; else index = 100;
    void* data = getData__9gfArchiveF11ARCNodeTypeiUs(self->archive, 2, index, 0xFFFE);
    if (data) { void* posData = data; createStagePositions__5StageFPQ34nw4r3g3d7ResFile(self, &posData); }
    else createStagePositions__5StageFv(self);
    ((signed char*)lbl_805A0360)[0x40] &= ~8;
    switch (self->control->mode) {
    case 0:
    case 4:
        fn_27_227B68(self->unk90, 1);
        {
            void* actor = self->unk90;
            ((f32*)actor)[5] = self->x;
            ((f32*)actor)[6] = self->y;
            ((f32*)actor)[7] = self->z;
        }
        ((u8*)lbl_805A0360)[0x40] |= 8;
        break;
    case 1:
    case 2:
    case 3:
        ((signed char*)self)[0x550] &= ~0x80;
        break;
    }
    self->fn_40_7D44();
}