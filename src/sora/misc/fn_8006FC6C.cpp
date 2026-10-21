#pragma force_active on
namespace ms {
class CharWriter {
public:
    void SetScale(float scale);
    char pad0[0x24];
    float unk24;
    float unk28;
};
}

void ms::CharWriter::SetScale(float scale) {
    unk24 = scale;
    unk28 = scale;
}
