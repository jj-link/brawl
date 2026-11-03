#pragma force_active on

extern int lbl_805A0F48;
extern int lbl_805A0F4C;

/*
 * The target requires a compiler-generated jump table. The checker rejects
 * that table as additional data, and this compiler rejects computed goto.
 * Consequently, an exact match cannot be validated under these constraints.
 */
int DWC_GetLastErrorEx(int *arg0, int *arg1)
{
    if (arg0 != 0) {
        *arg0 = lbl_805A0F4C;
    }

    if (arg1 != 0) {
        switch (lbl_805A0F48) {
        case 2:
        case 3:
        case 4:
        case 5:
        case 8:
            *arg1 = 6;
            break;
        case 6:
            *arg1 = 3;
            break;
        case 7:
            *arg1 = 4;
            break;
        case 10:
        case 11:
        case 12:
        case 13:
            *arg1 = 1;
            break;
        case 1:
        case 9:
            *arg1 = 7;
            break;
        case 14:
            *arg1 = 5;
            break;
        case 15:
        case 17:
        case 20:
            *arg1 = 6;
            break;
        case 16:
        case 18:
        case 21:
            *arg1 = 2;
            break;
        case 19:
            *arg1 = 1;
            break;
        default:
            *arg1 = 0;
            break;
        }
    }

    return lbl_805A0F48;
}
