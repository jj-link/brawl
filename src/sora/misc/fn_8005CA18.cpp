#pragma force_active on
extern "C" {
void fn_8005A99C(void* self);
void fn_8005AA08(void* self, void* out);
int fn_801643C8(void);
void fn_801645E8(int handle, void* out);
int fn_8016FBF4(void* p);
}

struct Hdr {
    unsigned int type : 8;
    unsigned int rest : 24;
};

extern "C" void fn_8005CA18(unsigned char* arg0) {
    unsigned char sp8[0x30];
    int handle;

    handle = fn_8016FBF4(arg0 + 0x4C);
    if (fn_801643C8() == 0) {
        Hdr* h = (Hdr*)(arg0 + 0xC);
        h->type = 3;
        if ((arg0[0x54] >> 7) & 1) {
            fn_8005A99C(arg0);
        }
    } else {
        fn_8005AA08(arg0, sp8);
        fn_801645E8(handle, sp8);
    }
}
