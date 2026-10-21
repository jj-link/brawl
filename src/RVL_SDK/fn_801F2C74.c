#pragma force_active on
typedef struct Flags {
    unsigned int unused : 24;
    unsigned int value : 3;
    unsigned int enabled : 1;
    unsigned int rest : 4;
} Flags;

extern unsigned char lbl_8059EAB8[8];

void fn_801F2C74(Flags *arg0, int arg1, int arg2)
{
    arg0->enabled = (arg2 == 1);
    arg0->value = lbl_8059EAB8[arg1];
}
