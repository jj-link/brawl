#pragma force_active on

namespace ms {

struct CharWriter {
    char pad0[0x2C];
    float cursorX;
    float cursorY;
    float cursorZ;

    void SetCursor(float x, float y, float z);
};

void CharWriter::SetCursor(float x, float y, float z) {
    cursorX = x;
    cursorY = y;
    cursorZ = z;
}

} // namespace ms
