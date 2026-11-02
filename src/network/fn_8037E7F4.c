#pragma force_active on
struct Obj {
    char pad0[0x3C];
    int unk3C;
    char pad1[0xD4];
    int unk114;
};

void fn_8037E7F4(struct Obj* arg0) {
    int v = arg0->unk114;
    int q = v / 100;
    switch (q) {
    case 1:
        return;
    case 2:
        break;
    case 3:
        return;
    default:
        return;
    case 4:
        switch (v) {
        case 0x191:
            arg0->unk3C = 9;
            return;
        case 0x193:
            arg0->unk3C = 0xA;
            return;
        case 0x194:
        case 0x19A:
            arg0->unk3C = 0xB;
            return;
        case 0x192:
        default:
            arg0->unk3C = 8;
            return;
        }
    case 5:
        arg0->unk3C = 0xC;
        return;
    }
}
