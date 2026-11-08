#pragma force_active on

static inline void low(char* arg0, int arg1, short arg2)
{
    int flag = *(int*)(arg0 + 0x3C);
    if ((((unsigned int)flag >> 7) & 1U) >= 1U) {
        int value = arg2 & ~(arg2 >> 31);
        unsigned int data = *(unsigned int*)(arg0 + 0x38);
        int base = *(int*)(arg0 + 0x40);
        int offset = (((data >> 24) & 0xF) * 0x14) +
                     ((data >> 28) * 0x1C) +
                     ((data >> 18) & 0x3C) +
                     ((data >> 6) & 4);
        int address = base + offset;
        unsigned char clamped = (short)value > 0xFF ? 0xFF : value;

        switch (arg1 & 3) {
        case 0: *(unsigned char*)address = clamped; return;
        case 1: *(unsigned char*)(address + 1) = clamped; return;
        case 2: *(unsigned char*)(address + 2) = clamped; return;
        case 3: *(unsigned char*)(address + 3) = clamped; return;
        }
    }
    return;
}

static inline void half(char* arg0, int arg1, short arg2)
{
    unsigned int index = (unsigned int)(arg1 - 4) >> 2;

    switch ((arg1 - 4) & 3) {
    case 0: *(short*)(arg0 + index * 8 + 0x10) = arg2; return;
    case 1: *(short*)(arg0 + index * 8 + 0x12) = arg2; return;
    case 2: *(short*)(arg0 + index * 8 + 0x14) = arg2; return;
    case 3: *(short*)(arg0 + index * 8 + 0x16) = arg2; return;
    }
    return;
}

static inline void high(char* arg0, int arg1, short arg2)
{
    unsigned int index = (unsigned int)(arg1 - 0x10) >> 2;
    int value = arg2 & ~(arg2 >> 31);
    unsigned char clamped = (short)value > 0xFF ? 0xFF : value;

    switch ((arg1 - 0x10) & 3) {
    case 0: *(unsigned char*)(arg0 + index * 4 + 0x28) = (unsigned char)clamped; return;
    case 1: *(unsigned char*)(arg0 + index * 4 + 0x29) = (unsigned char)clamped; return;
    case 2: *(unsigned char*)(arg0 + index * 4 + 0x2A) = (unsigned char)clamped; return;
    case 3: *(unsigned char*)(arg0 + index * 4 + 0x2B) = (unsigned char)clamped; return;
    }
}

extern "C" void fn_80189ABC(char* arg0, int arg1, short arg2)
{
    if (arg1 >= 0x10) goto check_32;
    if (arg1 >= 4) goto halfword;
    if (arg1 >= 0) goto low_byte;
done:
    return;

check_32:
    if (arg1 >= 0x20) goto done;
    goto high_byte;

low_byte:
    low(arg0, arg1, arg2);
    return;

halfword:
    half(arg0, arg1, arg2);
    return;

high_byte:
    high(arg0, arg1, arg2);
}
