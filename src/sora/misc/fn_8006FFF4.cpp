#pragma force_active on
namespace ms {
class CharWriter {
public:
    void MoveCursorY(float);
    char pad[0x30];
    float y;
};
void CharWriter::MoveCursorY(float v) {
    y += v;
}
}
