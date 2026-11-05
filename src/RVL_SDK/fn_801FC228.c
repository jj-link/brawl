#include <string.h>
#pragma force_active on

int DVDCompareDiskID(const char *a, const char *b) {
    if (a[0] != 0 && b[0] != 0 && strncmp(a, b, 4) != 0) {
        return 0;
    }
    if (a[4] == 0 || b[4] == 0 || strncmp(a + 4, b + 4, 2) != 0) {
        return 0;
    }
    if ((unsigned char)a[6] != 0xFF && (unsigned char)b[6] != 0xFF && (unsigned char)a[6] != (unsigned char)b[6]) {
        return 0;
    }
    if ((unsigned char)a[7] != 0xFF && (unsigned char)b[7] != 0xFF && (unsigned char)a[7] != (unsigned char)b[7]) {
        return 0;
    }
    return 1;
}