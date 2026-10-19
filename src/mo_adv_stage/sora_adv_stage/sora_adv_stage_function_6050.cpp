#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;

    Vec3f& operator=(const Vec3f& v) {
        x = v.x;
        y = v.y;
        z = v.z;
        return *this;
    }
};

extern "C" {
extern void* g_GameGlobal;
extern void* g_ftManager;
extern const float lbl_40_rodata_2C[];

int getEntryId__9ftManagerFi(void*, int);
void* getFighter__9ftManagerFii(void*, int, int);
int isFighterActivate__9ftManagerFii(void*, int, int);
int fn_27_10A848(void*, int, int);
Vec3f getPos__23soExternalValueAccesserFP11StageObject(void*);
void getFighterReStartPos__5StageFP5Vec3fi(void*, Vec3f*, int);

void fn_40_6050(void* self, Vec3f* out, int arg) {
    float defaultValue = lbl_40_rodata_2C[0];
    out->z = defaultValue;
    out->y = defaultValue;
    out->x = defaultValue;

    int restart;
    void* modeObject = *(void**)((char*)g_GameGlobal + 0x30);
    if (modeObject != 0) {
        unsigned char mode = *(unsigned char*)((char*)modeObject + 0x604);
        if (mode == 1)
            goto do_restart;
        if (mode == 2)
            goto do_restart;
        if (mode != 3)
            goto no_restart;
    } else {
        goto no_restart;
    }
do_restart:
    restart = 1;
    goto check_restart;
no_restart:
    restart = 0;
check_restart:
    if (restart != 0)
        goto final_restart;

    switch (*(int*)((char*)self + 0x52c)) {
    case 0: {
        unsigned char flag = *(unsigned char*)((char*)self + 0x550);
        if (((flag >> 5) & 1) == 0 && arg == 0) {
            out->x = *(float*)((char*)self + 0x560);
            out->y = *(float*)((char*)self + 0x564);
            out->z = *(float*)((char*)self + 0x568);
            break;
        }

        int success;
        void* fighter;
        int entry = getEntryId__9ftManagerFi(g_ftManager, 0);
        if (entry == -1) {
            success = 0;
        } else {
            fighter = getFighter__9ftManagerFii(g_ftManager, entry, -1);
            if (fighter == 0) {
                success = 0;
            } else if (!isFighterActivate__9ftManagerFii(g_ftManager, entry, -1)) {
                success = 0;
            } else if (!fn_27_10A848(g_ftManager, entry, -1)) {
                success = 0;
            } else {
                *out = getPos__23soExternalValueAccesserFP11StageObject(fighter);
                success = 1;
            }
        }
        if (success == 0) {
            out->x = *(float*)((char*)self + 0x560);
            out->y = *(float*)((char*)self + 0x564);
            out->z = *(float*)((char*)self + 0x568);
        }
        break;
    }
    case 1:
        getFighterReStartPos__5StageFP5Vec3fi(self, out, arg);
        return;
    case 2:
        out->x = *(float*)((char*)self + 0x56c);
        out->y = *(float*)((char*)self + 0x570);
        out->z = *(float*)((char*)self + 0x574);
        break;
    default:
        break;
    }
    return;

final_restart:
    getFighterReStartPos__5StageFP5Vec3fi(self, out, arg);
}
}
