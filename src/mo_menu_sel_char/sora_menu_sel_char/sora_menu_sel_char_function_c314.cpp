#pragma force_active on
extern "C" {
int exchangeMuSelchkindToMuCharKind__6muMenuFiii(int, int, int);
int isCharUsable__6muMenuFiii(int);
int isCharRefered__6muMenuFiii(int);

int fn_10_C314(int unused, int a, int b) {
    int kind = exchangeMuSelchkindToMuCharKind__6muMenuFiii(a, a, b);
    if (b == 0) {
        if (!isCharUsable__6muMenuFiii(kind)) {
            return 0;
        }
    }
    if (isCharRefered__6muMenuFiii(kind) == 0) {
        return 1;
    }
    return 2;
}
}
