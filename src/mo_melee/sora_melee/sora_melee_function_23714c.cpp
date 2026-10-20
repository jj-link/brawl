#pragma force_active on
typedef unsigned char u8;
typedef int s32;

namespace Gimmick {
enum AreaKind { AREA_KIND_0 = 0 };
}

struct stTriggerData;

struct stTriggerMng {
    void* createTrigger(Gimmick::AreaKind kind, stTriggerData* data);
};

extern stTriggerMng* g_stTriggerMng;
extern char lbl_27_data_4C6F0[];
extern const float lbl_27_rodata_3920;

struct grGimmickFrameTriggerData {
    char pad[0x10];
};

class stActTriggerFrameExcelCB {
public:
    stActTriggerFrameExcelCB(grGimmickFrameTriggerData* data);
    s32 m_0;
    void* m_4;
    s32 m_8;
    float m_c;
    u8 m_10;
    grGimmickFrameTriggerData* m_14;
    void* m_18;
};

stActTriggerFrameExcelCB::stActTriggerFrameExcelCB(grGimmickFrameTriggerData* data) {
    m_0 = 0;
    m_14 = data;
    m_8 = 0;
    m_4 = lbl_27_data_4C6F0;
    m_c = lbl_27_rodata_3920;
    m_10 = 1;
    m_18 = g_stTriggerMng->createTrigger(Gimmick::AREA_KIND_0, (stTriggerData*)((char*)data + 0x10));
}
