#pragma force_active on
#pragma always_inline on
static inline short get_bias(unsigned int v) { return (v >> 9) & 0xff; }
static inline unsigned char get_edge(unsigned int v) { return (v >> 8) & 1; }
extern const double lbl_805A3828;
extern const double lbl_805A3850;
extern const float lbl_805A3848;
extern const float lbl_805A384C;
extern int lbl_8059EAC0;

typedef struct {
    unsigned int unk0;
    unsigned int unk4;
} Input;

void fn_801F2D60(
    const Input *arg0,
    int *arg1,
    int *arg2,
    float *arg3,
    float *arg4,
    float *arg5,
    signed char *arg6,
    unsigned char *arg7,
    int *arg_sp8
) {
    unsigned int temp_r28 = arg0->unk0;
    unsigned int temp_r0 = arg0->unk4;

    unsigned int filter_index = (temp_r28 >> 5) & 7;
    unsigned int mag = (temp_r28 >> 4) & 1;
    short bias = get_bias(temp_r28);
    unsigned char edge = get_edge(temp_r28);
    *arg1 = ((unsigned char *)&lbl_8059EAC0)[filter_index];
    *arg2 = mag;
    *arg3 = (float)(temp_r0 & 0xFF) * lbl_805A3848;
    *arg4 = (float)((temp_r0 >> 8) & 0xFF) * lbl_805A3848;
    *arg5 = (float)(signed char)bias * lbl_805A384C;
    *arg6 = (temp_r28 >> 21) & 1;
    *arg7 = !edge;
    *arg_sp8 = (temp_r28 >> 19) & 3;
}
