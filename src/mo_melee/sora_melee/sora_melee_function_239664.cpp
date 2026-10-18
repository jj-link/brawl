#pragma force_active on
struct Vec3f {
    float x, y, z;

    Vec3f& operator=(const Vec3f& v) {
        x = v.x;
        y = v.y;
        z = v.z;
        return *this;
    }
};

extern "C" {
extern void* g_ftManager;

int getEntryId__9ftManagerFi(void*, int);
int isFighterActivate__9ftManagerFii(void*, int, int);
int fn_27_10A848(void*, int, int);
void* getFighter__9ftManagerFii(void*, int, int);
Vec3f getPos__23soExternalValueAccesserFP11StageObject(void*);
Vec3f getHipPos__23ftExternalValueAccesserFP7Fighter(void*);
Vec3f fn_27_14D218(void*);

bool fn_27_239664(int id, Vec3f* out, int kind) {
    void* mgr = g_ftManager;
    int entry = getEntryId__9ftManagerFi(mgr, id);
    if (entry == -1)
        return false;
    if (!isFighterActivate__9ftManagerFii(mgr, entry, -1))
        return false;
    if (!fn_27_10A848(mgr, entry, -1))
        return false;

    void* fighter = getFighter__9ftManagerFii(mgr, entry, -1);
    if (fighter) {
        Vec3f pos;
        switch (kind) {
        case 0:
            pos = getPos__23soExternalValueAccesserFP11StageObject(fighter);
            break;
        case 1:
            pos = getHipPos__23ftExternalValueAccesserFP7Fighter(fighter);
            break;
        case 2:
            pos = fn_27_14D218(fighter);
            break;
        }
        *out = pos;
        return true;
    }
    return false;
}
}
