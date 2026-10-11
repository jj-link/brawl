/* Equal word alignment permits a byte head followed by word-wide copies.
   The word containing NUL is finished bytewise, so no destination bytes
   beyond the terminator are changed. */

typedef unsigned int u32;

#pragma force_active on

char* strcpy(char* destination, const char* source) {
    char* d;
    const char* s;
    u32 destination_align;
    u32 align;
    u32 head;
    u32 w;
    u32 mask;
    u32 difference;
    unsigned char byte;

    destination_align = (u32)destination & 3u;
    d = destination;
    s = source;

    if (destination_align == (align = (u32)s & 3u)) {
        if (align != 0) {
            /* Check each copied byte before advancing to aligned words. */
            byte = (unsigned char)*s;
            *d = byte;
            if (byte == 0) {
                return destination;
            }
            for (head = 3u - align; head != 0; --head) {
                byte = (unsigned char)*++s;
                *++d = byte;
                if (byte == 0) {
                    return destination;
                }
            }
            ++d;
            ++s;
        }

        w = *(const u32*)s;
        mask = 0x80808080u;
        difference = w - 0x01010101u;
        difference &= ~w;
        if ((difference & mask) == 0) {
            d -= 4;
            do {
                d += 4;
                *(u32*)d = w;
                s += 4;
                w = *(const u32*)s;
                difference = w - 0x01010101u;
                difference &= ~w;
            } while ((difference & mask) == 0);
            d += 4;
        }
    }

    byte = (unsigned char)*s;
    *d = byte;
    if (byte == 0) {
        return destination;
    }
    do {
        byte = (unsigned char)*++s;
        *++d = byte;
    } while (byte != 0);

    return destination;
}
