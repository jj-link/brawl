#pragma force_active on
struct Header {
    int unk0;
    char pad[0xA - 4];
    unsigned short unkA;
};

extern "C" int fn_8015C1B0(Header* arg0, int arg1) {
    if (arg1 == 0) {
        return arg0->unk0;
    }
    return *(int*)((char*)arg1 + arg0->unkA + 4);
}
