#pragma force_active on
class MuObject {
public:
    void setFrameMatCol(float frame);
};

struct SelfObj {
    char pad[0x8c];
    MuObject* m_obj;
};

extern const float lbl_14_rodata_0;
extern "C" int fn_14_3424(int a, int b);

extern "C" void fn_14_4D2C(SelfObj* self) {
    fn_14_3424((int)self, 0xd);
    self->m_obj->setFrameMatCol(lbl_14_rodata_0);
}
