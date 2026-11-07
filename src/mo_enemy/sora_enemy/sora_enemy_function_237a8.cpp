#include <ft/ft_manager.h>
#pragma force_active on
extern "C" {
extern float lbl_41_rodata_D58;
Vec3f* fn_41_5AC4(Vec3f*, float, float, float);
int fn_27_10A848(ftManager*, int, int);
int fn_27_10A920(ftManager*, int);
Fighter* fn_41_237A8(unsigned int);
}
Fighter* fn_41_237A8(unsigned int arg) {
    Vec3f v;
    fn_41_5AC4(&v, lbl_41_rodata_D58, lbl_41_rodata_D58, lbl_41_rodata_D58);
    if (arg <= 3) {
        int entry = -1;
        if (arg <= 1) {
            entry = g_ftManager->getEntryId(0);
            if (entry == -1) return 0;
        } else if (arg - 2 <= 1) {
            entry = g_ftManager->getEntryId(1);
            if (entry == -1) return 0;
        }
        if ((int)arg == 0 || (int)arg == 2) {
            if (!fn_27_10A848(g_ftManager, entry, -1)) return 0;
        } else if ((int)arg == 1 || (int)arg == 3) {
            if (!fn_27_10A920(g_ftManager, entry)) return 0;
        }
        Fighter* result = 0;
        if ((int)arg == 0 || (int)arg == 2)
            result = g_ftManager->getFighter(entry, -1);
        else if ((int)arg == 1 || (int)arg == 3)
            result = g_ftManager->getSubFighter(entry);
        return result;
    }
    return 0;
}