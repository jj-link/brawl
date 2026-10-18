#pragma force_active on
class grGimmickMotionPath {
public:
    void setFrameUpdate(float frame);
};

extern const float lbl_40_rodata_3E4;

extern "C" void fn_40_26BE4(char* self, unsigned int idx)
{
    grGimmickMotionPath* path = *(grGimmickMotionPath**)(self + ((idx & 0xff) << 2) + 0x150);
    *(grGimmickMotionPath**)(self + 0xcc) = path;
    path->setFrameUpdate(lbl_40_rodata_3E4);
}
