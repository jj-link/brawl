#pragma force_active on
extern "C" void fn_27_11FD4C(char*, int, int, unsigned int, unsigned int, int);
extern "C" void fn_27_1220DC(char* self, int index, int arg, unsigned int kind, int id, unsigned int field, unsigned int value) {
    switch (kind) {
    case 15: *(unsigned int*)(self + 0x74) = value; return;
    case 1: *(unsigned int*)(self + id * 4 + 0x78) = value; return;
    case 4: *(unsigned int*)(self + 0x53c) = value; return;
    case 13:
        if (id == 12) {
            if (field == 12) *(unsigned int*)(self + 0x340) = value;
            else if (field == 13) *(unsigned int*)(self + 0x33c) = value;
            else if (field & 0x80) *(unsigned int*)(self + 0x344) = value;
            else *(unsigned int*)(self + (unsigned char)field * 4 + 0x30c) = value;
        } else *(unsigned int*)(self + id * 4 + 0x230) = value;
        return;
    case 14:
        if (id == 12) {
            if (field == 12) *(unsigned int*)(self + 0x458) = value;
            else if (field == 13) *(unsigned int*)(self + 0x454) = value;
            else if (field & 0x80) *(unsigned int*)(self + 0x45c) = value;
            else *(unsigned int*)(self + (unsigned char)field * 4 + 0x424) = value;
        } else *(unsigned int*)(self + id * 4 + 0x348) = value;
        return;
    case 12: *(unsigned int*)(self + id * 4 + 0x154) = value; return;
    case 10: *(unsigned int*)(self + id * 4 + 0x460) = value; return;
    default: fn_27_11FD4C(*(char**)self + index * 0x4d4, kind, id, field, value, arg); return;
    }
}