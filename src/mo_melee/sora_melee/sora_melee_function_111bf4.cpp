#pragma force_active on
typedef unsigned char u8;

extern "C" void* getInstance__9itManagerFv();
extern "C" void fn_27_2A96F4(void* mgr, int a, int b);

extern "C" {
void fn_27_111BF4(void* obj, u8 val) {
    u8* base = *(u8**)obj;
    u8* p = base + base[0x73];
    p[0x74] = val;
    base = *(u8**)obj;
    base[0x73]++;
    fn_27_2A96F4(getInstance__9itManagerFv(), val, 1);
}
}
