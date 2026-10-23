#include <nw4r/ut/ut_ResFont.h>
#pragma force_active on

extern float lbl_805A1A74;

namespace ms {

class CharWriter {
public:
    char pad0[0x48];
    void* m_font;
    char pad4C[0x1C];
    float m_104;

    void SetFont(const nw4r::ut::ResFont& font);
};

void ms::CharWriter::SetFont(const nw4r::ut::ResFont& font) {
    float f = lbl_805A1A74;
    m_font = const_cast<nw4r::ut::ResFont*>(&font);
    m_104 = f;
}

}
