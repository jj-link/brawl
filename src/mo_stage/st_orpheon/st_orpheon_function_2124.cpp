#pragma force_active on
struct ftManager;

extern "C" {
int getEntryId__9ftManagerFi(ftManager* self, int idx);
int isFighterActivate__9ftManagerFii(ftManager* self, int id, int arg);
int fn_27_10AAC4(ftManager* self, int id);
void fn_27_10A0F0(ftManager* self, int id, int arg);
}

extern ftManager* g_ftManager;

extern "C" void fn_55_2124(void* unused, int arg) {
    ftManager* mgr = g_ftManager;
    int i = 0;
    do {
        int id = getEntryId__9ftManagerFi(mgr, i);
        if (id != -1 && isFighterActivate__9ftManagerFii(mgr, id, -1) != 0) {
            int st = fn_27_10AAC4(mgr, id);
            if (st == 0x1D || st == 0x1F || st == 0x21) {
                fn_27_10A0F0(mgr, id, arg);
            }
        }
        i++;
    } while (i < 4);
}
