#pragma force_active on

extern int strcmp(const char *, const char *);
extern char *strcpy(char *, const char *);
extern unsigned long strlen(const char *);

extern char lbl_8059EB4C[2];
extern int lbl_8059EB50;

void fn_8020C874(char *arg0, const char *arg1)
{
    int i;

    if (strcmp(lbl_8059EB4C, arg1) == 0) {
        strcpy(arg0, (const char *)&lbl_8059EB50);
        return;
    }

    for (i = strlen(arg1) - 1; i >= 0; i--) {
        if (arg1[i] == '/') {
            break;
        }
    }

    strcpy(arg0, arg1 + i + 1);
}
