#pragma force_active on
extern int fn_803C2E94(int *);
extern char lbl_8053B248[];
typedef struct { unsigned int w[0x90]; } Payload;
static inline int find_id(int id)
{
    unsigned int i;
    char *entry = lbl_8053B248 + 8;
    for (i = 1; i < 1; i++) {
        if ((*(int *)(entry + 0x40) &= 1) &&
            id == *(int *)(entry + 0x44)) return 1;
        entry += 8;
    }
    return 0;
}
int fn_803C120C(char *arg0, char *arg1)
{
    int sp8;
    int id;
    unsigned int i;
    char *entry;
    unsigned int j;
    unsigned int found;
    if (arg0 == 0) return 10;
    if (!(*(unsigned short *)(arg0 + 0x1878) & 2)) return 9;
    fn_803C2E94(&sp8);
    id = sp8;
    for (i = 1, entry = arg0 + 0x248; i < 1; i++) {
        if ((*(unsigned int *)(entry + 0x1618) & 1) &&
            id == *(int *)(entry + 0x161C)) {
            *(Payload *)arg1 = *(Payload *)(arg0 + i * 0x248 + 0x1620);
            break;
        }
        entry += 0x248;
    }
    if (i == 1) {
        found = find_id(id);
        if (found) {
            entry = arg0 + 0x248;
            for (j = 1; j < 1; j++) {
                if (!(*(unsigned int *)(entry + 0x1618) & 1)) {
                    *(unsigned int *)(arg0 + j * 0x248 + 0x1618) |= 1;
                    *(int *)(arg0 + j * 0x248 + 0x161C) = sp8;
                    *(Payload *)arg1 = *(Payload *)(arg0 + j * 0x248 + 0x1620);
                    break;
                }
                entry += 0x248;
            }
        } else {
            *(Payload *)arg1 = *(Payload *)(arg0 + 0x1620);
        }
    }
    return 0;
}