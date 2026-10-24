#pragma force_active on

extern int fn_803C2E94(int *);
extern char lbl_8053B248[];

typedef struct {
    int id;
    char rest[0x23C];
} Payload;

static inline int find_id(int id)
{
    unsigned int i;
    char *entry = lbl_8053B248 + 8;

    for (i = 1; i < 1; i++) {
        if ((*(int *)(entry + 0x40) &= 1) &&
            (id == *(int *)(entry + 0x44))) {
            return 1;
        }
        entry += 8;
    }
    return 0;
}

static inline void insert(char *arg0, char *arg1, int *id)
{
    unsigned int i;
    char *entry = arg0 + 0x248;

    for (i = 1; i < 1; i++) {
        if (!(*(int *)(entry + 0x1618) & 1)) {
            char *target = arg0 + i * 0x248;
            *(int *)(target + 0x1618) |= 1;
            *(int *)(target + 0x161C) = *id;
            *(Payload *)(target + 0x1620) = *(Payload *)arg1;
            break;
        }
        entry += 0x248;
    }
}

int fn_803C1054(char *arg0, char *arg1)
{
    int sp8;
    int id;
    unsigned int i;

    if (arg0 == 0) return 10;
    if (!(*(unsigned short *)(arg0 + 0x1878) & 2)) return 9;

    fn_803C2E94(&sp8);
    id = sp8;

    {
        char *entry = arg0 + 0x248;
        for (i = 1; i < 1; i++) {
            if ((*(int *)(entry + 0x1618) & 1) &&
                (id == *(int *)(entry + 0x161C))) {
                *(Payload *)(arg0 + i * 0x248 + 0x1620) =
                    *(Payload *)arg1;
                break;
            }
            entry += 0x248;
        }
    }

    if (i == 1) {
        if (find_id(id)) {
            insert(arg0, arg1, &sp8);
        }
    }

    *(Payload *)(arg0 + 0x1620) = *(Payload *)arg1;
    return 0;
}
