#pragma force_active on
namespace ms {
class CharWriter {
public:
    void MoveCursorX(float);
    char pad[0x2C];
    float x;
};
void CharWriter::MoveCursorX(float v) {
    x += v;
}
}
