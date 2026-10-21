#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

struct StageObject;

extern "C" s32 fn_27_1190D0(void*);
extern "C" u8* getEntity__14ftEntryManagerFUl(void*, u32);
extern "C" float getLr__23soExternalValueAccesserFP11StageObject(StageObject*);

class ftManager {
public:
    float getFighterLr(int entryId, int index);
};

float ftManager::getFighterLr(int entryId, int index) {
    StageObject* obj;
    if (fn_27_1190D0(*(void**)((char*)this + 0x154)) == 0) {
        obj = 0;
    } else if (index != -1) {
        u8* e = getEntity__14ftEntryManagerFUl(*(void**)((char*)this + 0x154), entryId);
        obj = *(StageObject**)(e + (index << 3) + 0x34);
    } else {
        u8* e = getEntity__14ftEntryManagerFUl(*(void**)((char*)this + 0x154), entryId);
        obj = *(StageObject**)(e + (e[0xA] << 3) + 0x34);
    }
    return getLr__23soExternalValueAccesserFP11StageObject(obj);
}
