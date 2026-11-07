#pragma force_active on
extern "C" {
void* fn_94_CE94(void*, int);
void* fn_94_CE5C(void*, int);
void* fn_94_CE24(void*, int);
void* fn_94_CE0C(void*, int);
void* fn_94_CDC4(void*, int);
void* fn_94_CDAC(void*, int);
void* fn_94_CD84(void*, int);
void* fn_94_CD6C(void*, int);
int fn_27_8D3E4(void*);
}
extern "C" void fn_94_CB1C(char* pool) {
    for (int i = 0; i < 4; ++i)
        if (!fn_27_8D3E4(static_cast<char*>(fn_94_CE94(pool + 0x175f0, i)) + 0x88)) return;
    for (int i = 0; i < 3; ++i)
        if (!fn_27_8D3E4(static_cast<char*>(fn_94_CE5C(pool + 0x1260c, i)) + 0x88)) return;
    for (int i = 0; i < 3; ++i)
        if (!fn_27_8D3E4(static_cast<char*>(fn_94_CE24(pool + 0xda84, i)) + 0x88)) return;
    for (int i = 0; i < 1; ++i)
        if (!fn_27_8D3E4(static_cast<char*>(fn_94_CE0C(pool + 0xc184, i)) + 0x88)) return;
    for (int i = 0; i < 4; ++i)
        if (!fn_27_8D3E4(static_cast<char*>(fn_94_CDC4(pool + 0x6240, i)) + 0x88)) return;
    for (int i = 0; i < 1; ++i)
        if (!fn_27_8D3E4(static_cast<char*>(fn_94_CDAC(pool + 0x4a00, i)) + 0x88)) return;
    for (int i = 0; i < 2; ++i)
        if (!fn_27_8D3E4(static_cast<char*>(fn_94_CD84(pool + 0x17a4, i)) + 0x88)) return;
    for (int i = 0; i < 1; ++i)
        if (!fn_27_8D3E4(static_cast<char*>(fn_94_CD6C(pool + 0xc, i)) + 0x88)) return;
}