#pragma force_active on
struct St {
    unsigned char pad[0x6c];
    unsigned char hi : 4;
    unsigned char flag : 1;
    unsigned char lo : 3;
};

extern "C" int fn_42_774(St *p) {
    return p->flag;
}
