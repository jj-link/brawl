#pragma force_active on
namespace nw4r {
namespace ut {
struct Color {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
    Color() {}
    ~Color() {}
};
}
}

namespace ms {
class CharWriter {
public:
    unsigned char _pad[0x18];
    nw4r::ut::Color m_textColor;

    nw4r::ut::Color GetTextColor() const;
};

nw4r::ut::Color CharWriter::GetTextColor() const {
    return m_textColor;
}
}
