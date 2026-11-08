#include <ms/ms_char_writer.h>
#pragma force_active on
void ms::CharWriter::SetAlpha(unsigned char alpha) {
    m_alpha = alpha;
    m_colorRect.m_topLeft = m_textColor;
    m_colorRect.m_topRight = *reinterpret_cast<int*>(&m_32) != 1 ? m_textColor : m_unkColor;
    m_colorRect.m_bottomLeft = *reinterpret_cast<int*>(&m_32) != 2 ? m_textColor : m_unkColor;
    m_colorRect.m_bottomRight = *reinterpret_cast<int*>(&m_32) == 0 ? m_textColor : m_unkColor;
    m_colorRect.m_topLeft.a = m_colorRect.m_topLeft.a * m_alpha / 255;
    m_colorRect.m_topRight.a = m_colorRect.m_topRight.a * m_alpha / 255;
    m_colorRect.m_bottomLeft.a = m_colorRect.m_bottomLeft.a * m_alpha / 255;
    m_colorRect.m_bottomRight.a = m_colorRect.m_bottomRight.a * m_alpha / 255;
}