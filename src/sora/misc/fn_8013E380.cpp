#pragma force_active on
struct Bits { unsigned int flag:1; unsigned int field:8; unsigned int rest:23; };
struct ByteBits { unsigned char flag:1; };
extern "C" int fn_8013E380(void* self, signed char arg) {
    char* p = (char*)self;
    if (*(int*)(p + 0xa8) != 6 || *(int*)(p + 0x1e0) != 0) return 0;
    if ((int)((*(unsigned int*)(p + 0x1d8) << 1) & 0xff800000) >> 24) return 0;
    ((ByteBits*)(p + 0x1d8))->flag = 1;
    *(int*)(p + 0x1dc) = 0x50;
    ((Bits*)(p + 0x1d8))->field = 2;
    *(signed char*)(p + 0x1da) = arg;
    return 1;
}
