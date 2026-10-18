#pragma force_active on
struct Inner {
    char pad[0x9c];
    int value;
};

struct Entry {
    Inner* m_0;
    int m_4;
    int m_8;
};

extern Entry lbl_27_bss_3210[];

extern "C" {
int fn_27_147D64(int, int p1) {
    return lbl_27_bss_3210[p1].m_0->value;
}
}
