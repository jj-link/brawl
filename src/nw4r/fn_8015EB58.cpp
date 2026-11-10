#include <ms/ms_char_writer.h>
#pragma force_active on

namespace {
struct SrcColor {
    unsigned char r, g, b, a;
};
}

extern "C" void fn_8015EB58(ms::CharWriter* self, const nw4r::ut::Color& src) {
    self->m_textColor = src;
    self->m_colorRect.m_topLeft = src;
    self->m_colorRect.m_topRight = *reinterpret_cast<int*>(&self->m_32) != 1 ? self->m_textColor : self->m_unkColor;
    self->m_colorRect.m_bottomLeft = *reinterpret_cast<int*>(&self->m_32) != 2 ? self->m_textColor : self->m_unkColor;
    self->m_colorRect.m_bottomRight = *reinterpret_cast<int*>(&self->m_32) == 0 ? self->m_textColor : self->m_unkColor;
    self->m_colorRect.m_topLeft.a = self->m_colorRect.m_topLeft.a * self->m_alpha / 255;
    self->m_colorRect.m_topRight.a = self->m_colorRect.m_topRight.a * self->m_alpha / 255;
    self->m_colorRect.m_bottomLeft.a = self->m_colorRect.m_bottomLeft.a * self->m_alpha / 255;
    self->m_colorRect.m_bottomRight.a = self->m_colorRect.m_bottomRight.a * self->m_alpha / 255;
}