#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

extern "C" {
extern void* g_ftManager;

int getEntryId__9ftManagerFi(void*, int);
void* getFighter__9ftManagerFii(void*, int, int);
int isFighterActivate__9ftManagerFii(void*, int, int);
int fn_27_10A848(void*, int, int);
Vec3f getPos__23soExternalValueAccesserFP11StageObject(void*);

int fn_40_5EEC(void* self, int arg, Vec3f* out) {
    int entry = getEntryId__9ftManagerFi(g_ftManager, arg);
    if (entry == -1) {
        return 0;
    }
    void* fighter = getFighter__9ftManagerFii(g_ftManager, entry, -1);
    if (fighter == 0) {
        return 0;
    }
    if (!isFighterActivate__9ftManagerFii(g_ftManager, entry, -1)) {
        return 0;
    }
    if (!fn_27_10A848(g_ftManager, entry, -1)) {
        return 0;
    }
    *out = getPos__23soExternalValueAccesserFP11StageObject(fighter);
    return 1;
}
}
