// Runtime.PPCEABI.H/fn_803FA798.c
// Provenance: reconstructs build/RSBE01_02/asm/Runtime.PPCEABI.H/fn_803FA798.s
// (MSL strstr). Behavior recovered from the target disassembly.

char* strstr(const char* str, const char* sub) {
    const unsigned char* scan = (const unsigned char*)str - 1;
    const unsigned char* pat = (const unsigned char*)sub;
    unsigned int first;
    unsigned int c;
    unsigned int b;
    int found;
    const unsigned char* s2;
    const unsigned char* p2;

    if (sub == 0) {
        return (char*)str;
    }
    first = *pat;
    if (first == 0) {
        return (char*)str;
    } else {
        while ((c = *++scan) != 0) {
            if (c == first) {
                s2 = scan - 1;
                p2 = pat - 1;
                do {
                    c = *++s2;
                    b = *++p2;
                    found = c != b;
                } while (!found && c != 0);
                if (b == 0) {
                    return (char*)scan;
                }
            }
        }
    }
    return 0;
}
