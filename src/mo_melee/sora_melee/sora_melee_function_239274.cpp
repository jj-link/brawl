#include <st/st_melee.h>
#include <st/st_positions.h>
#include <st/st_trigger.h>
#include <mt/mt_vector.h>
#include <nw4r/ut/ut_algorithm.h>
#include <string.h>
#pragma force_active on

extern const float lbl_27_rodata_3930[];
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, Heaps::HeapType);
extern "C" void* fn_27_2336E8(void* self, void* arg);

bool stMelee::createWind2ndOnly()
{
    const float* data = lbl_27_rodata_3930;
    char* src = *(char**)((char*)this + 0x98);
    if (src == 0) {
        return false;
    }
    if (*(u8*)(src + 0xC9) == 0) {
        return false;
    }
    stPositions* pos = *(stPositions**)((char*)this + 0x90);
    if (pos == 0) {
        return false;
    }
    m_wind2ndData = (grGimmickWindData2nd*)__nw__FUlQ25Heaps8HeapType(0x4C, (Heaps::HeapType)0xF);
    if (m_wind2ndData == 0) {
        return false;
    }

    Vec3f center;
    Rect2D range;
    if (pos != 0) {
        pos->getCameraCenter(&center);
        pos->getDeadRange(&range);
    } else {
        center.m_x = data[0];
        center.m_y = data[0];
        center.m_z = data[0];
        range.m_up = data[4];
        range.m_down = data[5];
        range.m_right = data[5];
        range.m_left = data[4];
    }

    memset(m_wind2ndData, 0, 0x4C);
    char* w = (char*)m_wind2ndData;
    *(float*)(w + 0x28) = center.m_x;
    *(float*)(w + 0x2C) = center.m_y;
    *(float*)(w + 0x30) = center.m_z;
    *(float*)((char*)m_wind2ndData + 0x34) = *(float*)(src + 0xCC);
    *(float*)((char*)m_wind2ndData + 0x38) = *(float*)(src + 0xD0);
    *(float*)((char*)m_wind2ndData + 0x3C) = *(float*)(src + 0xD4);
    *(float*)((char*)m_wind2ndData + 0x40) = *(float*)(src + 0xD8);
    *(float*)((char*)m_wind2ndData + 0x44) = *(float*)(src + 0xDC);
    *(s32*)((char*)m_wind2ndData + 0x48) = *(s32*)(src + 0xE0);
    w = (char*)m_wind2ndData;
    *(float*)(w + 0x18) = data[0];
    *(float*)(w + 0x1C) = data[0];

    float fl = range.m_left;
    float fr = range.m_right;
    if (nw4r::ut::Abs(fl) > nw4r::ut::Abs(fr)) {
        *(float*)(w + 0x20) = data[6] + data[7] * nw4r::ut::Abs(fl);
    } else {
        *(float*)(w + 0x20) = data[6] + data[7] * nw4r::ut::Abs(fr);
    }

    float fu = range.m_up;
    float fd = range.m_down;
    if (nw4r::ut::Abs(fu) > nw4r::ut::Abs(fd)) {
        *(float*)(w + 0x24) = data[6] + data[7] * nw4r::ut::Abs(fu);
    } else {
        *(float*)(w + 0x24) = data[6] + data[7] * nw4r::ut::Abs(fd);
    }

    stTrigger* trigger = g_stTriggerMng->createTrigger((Gimmick::AreaKind)0xD, -1);
    m_wind2ndTrigger = trigger;
    if (trigger == 0) {
        return false;
    }
    fn_27_2336E8(trigger, m_wind2ndData);
    return true;
}
