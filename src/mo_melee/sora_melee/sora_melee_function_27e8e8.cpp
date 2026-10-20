#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

class ftManager {
public:
    static int getPlayerNo(int);
};

extern "C" ftManager* g_ftManager;
extern "C" u8* lbl_27_bss_5668;

struct FtInner {
    u8 pad[0x1a];
    u16 field1a;
};

struct FtOuter {
    u8 pad[0xc];
    FtInner* inner;
};

extern "C" void fn_27_27E8E8(FtOuter* p) {
    u8* b = lbl_27_bss_5668;
    if (b != 0) {
        if (p->inner->field1a == 0x1c) {
            if (b != 0) {
                int n = ftManager::getPlayerNo((int)g_ftManager);
                u8* q = (n & 3) + lbl_27_bss_5668;
                q[0x954] = 0;
            }
        }
    }
}
