// Runtime.PPCEABI.H/fn_803FA078.c
// Provenance: MSL __StringRead va_list character-source callback,
// reconstructed from the Brawl target (build/RSBE01_02/asm/Runtime.PPCEABI.H/
// fn_803FA078.s); behavior matches Melee's src/MSL/string.c __StringRead (MIT).

typedef unsigned char u8;

struct __InStrCtrl {
    u8* NextChar;
    int NullCharDetected;
};

int fn_803FA078(struct __InStrCtrl* isc, int ch, int mode) {
    int ret_val;
    switch (mode) {
    case 0:
        ret_val = *isc->NextChar;
        if ((char) ret_val == '\0') {
            isc->NullCharDetected = 1;
            return -1;
        }
        isc->NextChar += 1;
        return ret_val;
    case 1:
        if (isc->NullCharDetected == 0) {
            isc->NextChar -= 1;
        } else {
            isc->NullCharDetected = 0;
        }
        return ch;
    case 2:
        return isc->NullCharDetected;
    default:
        return 0;
    }
}
