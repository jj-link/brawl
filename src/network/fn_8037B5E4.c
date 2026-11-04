#pragma force_active on
extern void fn_8035E00C(void*);
extern void* memset(void*, int, unsigned int);

struct Unnamed_8037B5E4 {
    int unk0;
    int unk4;
    char pad8[0x14];
    int unk1C;
    char pad20[4];
};

void fn_8037B5E4(struct Unnamed_8037B5E4* arg0) {
    if (arg0 != 0) {
        int temp_r4 = arg0->unk4;
        if (temp_r4 != 0) {
            if (arg0->unk1C == 0) {
                fn_8035E00C((void*)temp_r4);
            }
            memset(arg0, 0, 0x24);
        }
    }
}