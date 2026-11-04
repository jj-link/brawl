#pragma force_active on
#include <it/it_manager.h>

extern "C" float fn_27_2AB498(void* base, int idx);
extern "C" void fn_27_2AB4D4(void* self, int idx, float val);
extern const float lbl_27_rodata_F48;

extern "C" void fn_27_112640(void* arg0, u32 arg1, float farg0, float farg1) {
    const float* rod = &lbl_27_rodata_F48;
    int off = *(s32*)(*(char**)arg0 + 0x7f8) * 12;
    *(u32*)(*(char**)arg0 + off + 0x4f8) = arg1;
    *(float*)(*(char**)arg0 + off + 0x4fc) = farg0;
    *(float*)(*(char**)arg0 + off + 0x500) = farg1;
    switch (arg1) {
    case 2:
        *(float*)(*(char**)arg0 + 0x7fc) = rod[1] + farg0 * rod[3] / rod[4];
        break;
    case 3:
        *(float*)(*(char**)arg0 + 0x800) = rod[1] - farg0 * rod[3] / rod[4];
        break;
    case 0x1C:
        *(s32*)(*(char**)arg0 + 0x804) = (s32)(farg0 * rod[3]);
        break;
    case 4:
    case 5: {
        char* p = *(char**)arg0;
        *(float*)(p + 0x4a0) = *(float*)(p + 0x4a0) * farg0;
        break;
    }
    case 0x1E:
        *(float*)(*(char**)arg0 + 0x808) = farg0;
        break;
    case 0x1F:
        *(s32*)(*(char**)arg0 + 0x814) = (s32)farg0;
        break;
    case 0x20:
        *(s32*)(*(char**)arg0 + 0x810) = -(s32)farg0;
        break;
    case 0x21:
        *(float*)(*(char**)arg0 + 0x80c) = rod[5] * farg0;
        break;
    case 0x22:
        *(float*)(*(char**)arg0 + 0x818) = farg0;
        break;
    case 0x24:
        *(float*)(*(char**)arg0 + 0x824) = farg0;
        *(s32*)(*(char**)arg0 + 0x828) = (s32)farg1;
        break;
    case 0x25:
        *(float*)(*(char**)arg0 + 0x81c) = farg0;
        break;
    case 0x26:
        *(float*)(*(char**)arg0 + 0x820) = farg0;
        break;
    case 0x27:
        *(float*)(*(char**)arg0 + 0x82c) = rod[0];
        break;
    case 0x2D:
        *(s32*)(*(char**)arg0 + 0x830) = (s32)farg0 * 60;
        break;
    case 0x2E:
        *(float*)(*(char**)arg0 + 0x834) = farg0;
        break;
    case 0x46:
        *(float*)(*(char**)arg0 + off + 0x4fc) = rod[6];
        break;
    case 0x47:
        *(float*)(*(char**)arg0 + off + 0x4fc) = rod[7];
        break;
    case 0x48:
        *(float*)(*(char**)arg0 + off + 0x4fc) = rod[8];
        break;
    case 0x49:
        *(float*)(*(char**)arg0 + off + 0x4fc) = rod[9];
        break;
    case 0x4A:
        *(float*)(*(char**)arg0 + off + 0x4fc) = rod[10];
        break;
    case 0x4B:
        *(float*)(*(char**)arg0 + off + 0x4fc) = rod[11];
        break;
    case 0x4C:
        *(float*)(*(char**)arg0 + off + 0x4fc) = rod[12];
        break;
    case 0x4D:
        *(float*)(*(char**)arg0 + off + 0x4fc) = rod[13];
        break;
    case 0x4E:
        *(float*)(*(char**)arg0 + off + 0x4fc) = rod[14];
        break;
    case 0x4F:
        *(float*)(*(char**)arg0 + off + 0x4fc) = rod[15];
        break;
    case 0x50:
        *(float*)(*(char**)arg0 + off + 0x4fc) = rod[16];
        break;
    case 0x51:
        *(float*)(*(char**)arg0 + off + 0x4fc) = rod[17];
        break;
    case 0x52:
        *(float*)(*(char**)arg0 + off + 0x4fc) = rod[18];
        break;
    case 0x53:
        *(float*)(*(char**)arg0 + off + 0x4fc) = rod[19];
        break;
    case 0x54:
        *(float*)(*(char**)arg0 + off + 0x4fc) = rod[20];
        break;
    case 0x55:
        *(float*)(*(char**)arg0 + off + 0x4fc) = rod[21];
        break;
    case 0x56:
        *(float*)(*(char**)arg0 + off + 0x4fc) = rod[22];
        break;
    case 0x57:
        *(float*)(*(char**)arg0 + off + 0x4fc) = rod[23];
        break;
    case 0x58:
        *(float*)(*(char**)arg0 + off + 0x4fc) = rod[24];
        break;
    case 0x59:
        *(float*)(*(char**)arg0 + off + 0x4fc) = rod[25];
        break;
    case 0x28:
        farg0 = farg0 + fn_27_2AB498(itManager::getInstance(), 0x33);
        fn_27_2AB4D4(itManager::getInstance(), 0x33, farg0);
        break;
    case 0x2B:
        farg0 = farg0 + fn_27_2AB498(itManager::getInstance(), 0x17);
        fn_27_2AB4D4(itManager::getInstance(), 0x17, farg0);
        break;
    case 0x2C:
        farg0 = farg0 + fn_27_2AB498(itManager::getInstance(), 0x48);
        fn_27_2AB4D4(itManager::getInstance(), 0x48, farg0);
        break;
    }
    {
        char* p = *(char**)arg0;
        *(s32*)(p + 0x7f8) = *(s32*)(p + 0x7f8) + 1;
    }
}
