#pragma force_active on
class grGimmick;
typedef void (grGimmick::*PFN_grGimmick)(float);

struct PtmfTable {
    PFN_grGimmick fn[6];
};

extern const PtmfTable lbl_40_rodata_890;

class grGimmick {
public:
    void update(float deltaFrame);
    void updateCallback(unsigned long arg);
    char pad[0x150];
    int m_kind;
};

extern "C" void fn_40_3D05C(grGimmick* self, float deltaFrame) {
    self->update(deltaFrame);
    PtmfTable table = lbl_40_rodata_890;
    (self->*table.fn[self->m_kind])(deltaFrame);
    self->updateCallback(0);
}
