#include <it/it_manager.h>
#pragma force_active on
extern "C" int fn_27_2974B0(void* self, char* arg) {
    switch (*(int*)(arg + 0x8c0)) {
    case 0: case 4: case 12: case 23: case 26: case 40: case 50: case 58:
    case 63: case 64: case 65: case 66: case 69: case 70: case 71: case 73:
        return 3;
    case 160:
        return 5;
    case 75: case 76:
        return 0;
    case 110: case 118: case 119: case 134: case 135: {
        int kind = *(int*)((char*)itManager::getInstance() + 0x54);
        int result = 2;
        if (kind == 0x24)
            result = 0;
        return result;
    }
    default:
        return 2;
    }
}