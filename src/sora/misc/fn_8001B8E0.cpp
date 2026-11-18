#include <gf/gf_error_manager.h>

#pragma force_active on
extern "C" void fn_8001B8E0(int result, int flag) {
    switch (result) {
    default:
    case 0:
    case -8:
        return;
    case -128:
        break;
    case -64:
        break;
    case -16:
    case -15:
    case -14:
    case -13:
    case -12:
        break;
    case -10:
        break;
    case -6:
    case -5:
        break;
    case -1:
        break;
    case -2:
        if (flag == 0)
            gfErrorManager::getInstance()->notifyError(8, 0);
        break;
    case -3:
        if (flag == 0)
            gfErrorManager::getInstance()->notifyError(8, 0);
        break;
    case -4:
        gfErrorManager::getInstance()->notifyError(5, 0);
        break;
    case -9:
        gfErrorManager::getInstance()->notifyError(6, 0);
        break;
    case -11:
        gfErrorManager::getInstance()->notifyError(7, 0);
        break;
    }
}
