#pragma force_active on

extern int fn_80230500(void);
extern char lbl_804FD448[];

void fn_8022FFDC(int arg0) {
    int idx = fn_80230500();

    switch (arg0) {
    case 0:
        *(int *)(lbl_804FD448 + 0x28880 + ((idx << 2) & 0x3FC)) = 0;
        *(int *)(lbl_804FD448 + 0x28860 + ((idx << 2) & 0x3FC)) = 0;
        return;
    case 1:
        *(int *)(lbl_804FD448 + 0x288C0 + ((idx << 2) & 0x3FC)) = 0;
        *(int *)(lbl_804FD448 + 0x288A0 + ((idx << 2) & 0x3FC)) = 0;
        return;
    }
}
