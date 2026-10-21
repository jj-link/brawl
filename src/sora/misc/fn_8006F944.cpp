#include <nw4r/ut/ut_Color.h>
#include <ms/ms_char_writer.h>
#pragma force_active on

namespace ms {
void CharWriter::SetColorMapping(nw4r::ut::Color a, nw4r::ut::Color b) {
    m_colorMapping1 = a;
    m_colorMapping2 = b;
}
} // namespace ms
