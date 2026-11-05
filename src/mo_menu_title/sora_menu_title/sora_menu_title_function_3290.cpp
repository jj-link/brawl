#pragma force_active on
struct Input {
    unsigned char pad0[0xC];
    unsigned int flags;
    unsigned char pad10[0x2C];
    int mode;

    bool hasInput() const {
        return flags != 0;
    }
};

extern "C" unsigned int fn_24_3290(void*, Input* input) {
    if (input->hasInput()) {
        unsigned int flags = input->flags;
        if (flags & 0x2000)
            return 0;
        if (flags & 1)
            return 0;
        if (flags & 2)
            return 0;
        if (flags & 8)
            return 0;
        if (flags & 4)
            return 0;

        switch (input->mode) {
        case 0:
            if (flags & 0x40)
                return 0;
            if (flags & 0x20)
                return 0;
            if (flags & 0x10)
                return 0;
            break;
        case 1:
            if (flags & 0x800000)
                return 0;
            if (flags & 0x40)
                return 0;
            if (flags & 0x20)
                return 0;
            if (flags & 0x4000)
                return 0;
            if (flags & 0x8000)
                return 0;
            break;
        case 2:
            break;
        case 3:
            if (flags & 0x40000)
                return 0;
            if (flags & 0x10)
                return 0;
            break;
        default:
            break;
        }
        return 1;
    }
    return 0;
}