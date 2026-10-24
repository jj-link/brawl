#pragma force_active on

extern int lbl_8059ECB8;
extern int fn_80213090(int, int, int, int, void*);

int fn_80211720(void* arg0) {
    struct {
        int a;
        int b;
        char rest[0xC8];
        void* ptr;
        int eight;
        char tail[0x20];
    } buf __attribute__((aligned(32)));
    void* vec = &buf.ptr;
    int result;
    int* obj = (int*)arg0;
    int a;
    int b;

    if (lbl_8059ECB8 < 0 || arg0 == (void*)0) {
        return -0x3F9;
    }

    buf.ptr = &buf.a;
    buf.eight = 8;
    result = fn_80213090(lbl_8059ECB8, 0x20, 0, 1, vec);
    if (result == 0) {
        a = buf.a;
        b = buf.b;
        obj[1] = b;
        obj[0] = a;
    }
    return result;
}
