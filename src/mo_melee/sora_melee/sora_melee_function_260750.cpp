#pragma force_active on
#include <string.h>

extern "C" void* GetResNode__Q34nw4r3g3d6ResMdlCFPCc(void* self, const char* name);

struct Ground_base { char pad[0x3c]; };

class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void processAnim();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void processFixPosition();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void processFixCamera();
    virtual void processEffect();
    virtual void processGameProc();
    virtual void processEnd();
    virtual void renderPre();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void renderDebug();
    virtual void init();
    virtual void slot22();
    virtual void slot23();
    virtual void loadGroundData();
    virtual void slot25();
    virtual void setupMelee();
    virtual void slot27();
    virtual void setVisibilityByClipping();
    virtual void slot29();
    virtual void receiveCollMsg();
    virtual void slot31();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual int getModelCount();
    char pad40[4];
    void** m_44;
};

extern "C" int fn_27_260750(Ground* self, const char* name, const char* subName, unsigned int* outIndex, short* outValue) {
    unsigned int count = self->getModelCount();
    int off;
    int found = 0;
    unsigned int i;

    for (i = 0, off = 0; i < count; off += 4, i++) {
        void* obj = *(void**)((char*)self->m_44 + off);
        void* model = *(void**)((char*)obj + 0xe8);
        int nameOfs = *(int*)((char*)model + 0x3c);
        const char* modelName = nameOfs != 0 ? (const char*)((char*)model + nameOfs) : 0;
        if (strcmp(modelName, name) == 0) {
            void* res = GetResNode__Q34nw4r3g3d6ResMdlCFPCc(&model, subName);
            if (res != 0) {
                *outIndex = i;
                *outValue = (short)(res ? *(int*)((char*)res + 0xc) : 0);
                found = 1;
                break;
            }
        }
    }
    return found;
}
