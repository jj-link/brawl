#pragma force_active on
extern void PF_enterCritical(void *);
extern void PF_exitCritical(void *);
extern void fn_803EBBDC(int *);
extern char lbl_805644C0[];
typedef struct { unsigned int w[0x90]; } Payload;
typedef struct { unsigned int flag; int id; } Rec8;
static inline int find_id(int id)
{
    unsigned int i;
    char *entry = lbl_805644C0 + 8;
    for (i = 1; i < 4; i++) {
        if ((*(unsigned int *)(entry + 0x80) &= 1) &&
            id == *(int *)(entry + 0x84)) return 1;
        entry += 8;
    }
    return 0;
}
int fn_803E9D60(char *arg0, char *arg1)
{
    int sp8;
    int id;
    unsigned int i;
    char *entry;
    unsigned int j;
    Rec8 *rec;
    unsigned int found;
    if (!(*(unsigned short *)(arg0 + 0x1F8C) & 8)) return 9;
    PF_enterCritical(lbl_805644C0 + 0x64);
    fn_803EBBDC(&sp8);
    id = sp8;
    for (i = 1, entry = arg0 + 0x248; i < 4; i++) {
        if ((*(unsigned int *)(entry + 0x1654) & 1) &&
            id == *(int *)(entry + 0x1658)) {
            *(Payload *)arg1 = *(Payload *)(arg0 + i * 0x248 + 0x165C);
            break;
        }
        entry += 0x248;
    }
    if (i == 4) {
        found = find_id(id);
        if (found) {
            entry = arg0 + 0x248;
            for (j = 1; j < 4; j++) {
                if (!(*(unsigned int *)(entry + 0x1654) & 1)) {
                    *(unsigned int *)(arg0 + j * 0x248 + 0x1654) |= 1;
                    *(int *)(arg0 + j * 0x248 + 0x1658) = sp8;
                    *(Payload *)arg1 = *(Payload *)(arg0 + j * 0x248 + 0x165C);
                    break;
                }
                entry += 0x248;
            }
        } else {
            *(Payload *)arg1 = *(Payload *)(arg0 + 0x165C);
        }
    }
    PF_exitCritical(lbl_805644C0 + 0x64);
    return 0;
}