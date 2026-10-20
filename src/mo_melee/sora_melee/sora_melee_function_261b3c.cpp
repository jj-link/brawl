#pragma force_active on
extern "C" {
extern char* lbl_27_bss_5668;
void fn_27_228FD8(void* a, void* b);
}

class Ground {
public:
    void preExit();
};

void Ground::preExit() {
    fn_27_228FD8(*(void**)((char*)lbl_27_bss_5668 + 0xc4), this);
}
