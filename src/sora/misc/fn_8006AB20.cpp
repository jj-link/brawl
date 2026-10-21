#pragma force_active on
namespace nw4r { namespace ut {
struct Color {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};
}}

namespace ms {
class CharWriter {
    char _pad[0x5C];
    float m_edgeWidth;
    nw4r::ut::Color m_edgeColor;
public:
    void SetEdge(float width, nw4r::ut::Color color);
};

void CharWriter::SetEdge(float width, nw4r::ut::Color color) {
    m_edgeWidth = width;
    m_edgeColor.r = color.r;
    m_edgeColor.g = color.g;
    m_edgeColor.b = color.b;
    m_edgeColor.a = color.a;
}
}
