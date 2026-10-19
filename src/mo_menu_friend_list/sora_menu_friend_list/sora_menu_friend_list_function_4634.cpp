#pragma force_active on
class MuObject {
public:
    void setFrameMatCol(float frame);
};

struct SelfObj {
    char pad0[0xac];
    MuObject* m_obj;
    char pad1[0x24e0 - 0xb0];
    int unk24e0;
};

extern const float lbl_14_rodata_204;
extern "C" int fn_14_3424(int a, int b);

extern "C" void fn_14_4634(SelfObj* self) {
    fn_14_3424((int)self, 0xb);
    self->m_obj->setFrameMatCol(lbl_14_rodata_204);
    self->unk24e0 = 1;
}
