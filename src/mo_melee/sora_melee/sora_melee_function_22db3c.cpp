#include <stl/internal/mem.h>
#pragma force_active on

struct Piece {
    unsigned int w;
};

struct Entry {
    unsigned int w;
    char pad[0x14];
};

struct Obj {
    char pad0[0x2b4];
    int rows;
    int columns;
    char pad1[8];
    int runCount;
    int variant6Count;
    int variant3Count;
    int variant7Count;
    int extendedCount;
    int flaggedCount;
    unsigned int occupied[14];
    unsigned int solid[14];
    unsigned int centers[14];
    unsigned int tops[14];
    unsigned int extended[14];
    unsigned char grid[18][14];
    unsigned char minX;
    unsigned char minY;
    unsigned char maxX;
    unsigned char maxY;
    Entry entries[252];
};

extern "C" int fn_27_22D1D8(void*, int, void*, void*, int, int);

static inline void markOccupiedRows(Obj* obj, int y, int height, unsigned int mask) {
    for (int j = 0; j < height; ++j) {
        obj->occupied[y + j] |= mask;
    }
}

static inline void markSolidRows(Obj* obj, int y, int height, unsigned int mask) {
    for (int j = 0; j < height; ++j) {
        obj->solid[y + j] |= mask;
    }
}

static inline int marksTop(unsigned int w) {
    switch ((int)((w << 20) >> 30)) {
    case 0:
    case 2:
        return 1;
    case 3:
        if ((unsigned int)(((w >> 6) & 0xf) - 4) <= 4) {
            return 1;
        }
        break;
    }
    return 0;
}

static inline int marksExtendedRows(unsigned int w) {
    if (((w & 0xc00) >> 10) == 3) {
        switch ((int)((w >> 6) & 0xf)) {
        case 1:
        case 2:
        case 3:
        case 6:
            return 1;
        }
    }
    return 0;
}

static inline void markExtendedRows(Obj* obj, int y, int height, unsigned int mask,
                                    int offset, int extraRows) {

    height += extraRows;
    y += offset;
    for (int j = 0; j < height; ++j) {
        obj->extended[y + j] |= mask;
    }
}

static inline int marksSolidRows(unsigned int w) {
    switch ((int)((w >> 10) & 3)) {
    case 2:
        break;
    case 1:
        return 0;
    case 3:
        unsigned int variant = (w >> 6) & 0xf;
        if (variant == 1 || variant == 2 || variant == 3 || variant == 9) {
            return 0;
        }
        break;
    }
    return 1;
}

static inline void getCoordinates(unsigned int w, int& centerX, int& centerY,
                                  int& width, int& height) {
    int position = w >> 24;
    centerX = position % 18;
    centerY = position / 18;
    width = (w >> 21) & 7;
    height = (w >> 18) & 7;
    if (((w >> 18) & 1) == 0 && ((w & 7) == 2 || (w & 7) == 5)) {
        ++centerY;
    }
}

static inline int countRuns(Obj* obj, int columns) {
    int total = 0;
    unsigned int twoRowsBack = 0;
    unsigned int previousRow = 0;
    for (int j = 0; j < columns; ++j) {
        unsigned int top = obj->tops[j];
        if (top != 0) {
            top &= ~(twoRowsBack | previousRow);
            obj->tops[j] = top;
            if (top != 0) {
                top ^= top & (top << 1);
                unsigned int shifted = top >> 1;
                unsigned int pairs = (top & 0x55555555) + (shifted & 0x55555555);
                shifted = pairs >> 2;
                unsigned int nibbles = (pairs & 0x33333333) + (shifted & 0x33333333);
                unsigned int bytes = (nibbles + (nibbles >> 4)) & 0x0f0f0f0f;
                unsigned int halves = bytes + (bytes >> 8);
                unsigned int bits = halves + (halves >> 16);
                total += bits & 0xff;
            }
        }
        twoRowsBack = previousRow;
        previousRow = obj->solid[j];
    }
    return total;
}

extern "C" void fn_27_22DB3C(Obj* obj, unsigned int count, Piece* pieces) {
    int variant6Count;
    unsigned int pieceWord;
    int variant3Count;
    int variant7Count;
    int extendedCount;
    int flaggedCount;
    int minX;
    int minY;
    int maxX;
    int maxY;

    for (int j = 0; j < 14; ++j) {
        obj->occupied[j] = 0;
    }
    for (int j = 0; j < 14; ++j) {
        obj->solid[j] = 0;
    }
    for (int j = 0; j < 14; ++j) {
        obj->centers[j] = 0;
    }
    for (int j = 0; j < 14; ++j) {
        obj->tops[j] = 0;
    }
    for (int j = 0; j < 14; ++j) {
        obj->extended[j] = 0;
    }

    variant3Count = 0;
    variant7Count = 0;
    extendedCount = 0;
    flaggedCount = 0;
    minX = 255;
    minY = 255;
    maxX = 0;
    maxY = 0;

    memset((variant6Count = 0, obj->grid), 0xff, sizeof(obj->grid));

    for (unsigned int i = 0; i < count; ++i) {
        Piece piece = pieces[i];
        int centerX;
        int centerY;
        int width;
        int height;
        int x;
        int y;
        unsigned int limitX;
        unsigned int limitY;

        getCoordinates(piece.w, centerX, centerY, width, height);
        x = centerX - width / 2;
        y = centerY - height / 2;

        int right = x + width - 1;
        int bottom = y + height - 1;
        if (minX > x) {
            minX = x;
        }
        if (minY > y) {
            minY = y;
        }
        if (maxX < right) {
            maxX = right;
        }
        if (maxY < bottom) {
            maxY = bottom;
        }

        obj->entries[i].w = piece.w;
        limitX = obj->columns;
        limitY = obj->rows;
        for (int dx = 0; dx < width; ++dx) {
            for (int dy = 0; dy < height; ++dy) {
                if ((unsigned int)(x + dx) < limitX ||
                    (unsigned int)(y + dy) < limitY) {
                    obj->grid[x + dx][y + dy] = (unsigned char)i;
                }
            }
        }

        unsigned int mask = ((1U << width) - 1) << x;
        markOccupiedRows(obj, y, height, mask);

        if (marksTop(piece.w)) {
            obj->tops[y] |= mask;
        }

        if (marksExtendedRows(piece.w)) {
            int offset;
            int extraRows;
            switch ((int)((piece.w >> 6) & 0xf)) {
            case 1:
                offset = 0;
                extraRows = 1;
                break;
            case 2:
                offset = -1;
                extraRows = 1;
                break;
            case 6:
                offset = -1;
                extraRows = 2;
                break;
            default:
                offset = 0;
                extraRows = 0;
                break;
            }

            markExtendedRows(obj, y, height, mask, offset, extraRows);
            ++extendedCount;
        }

        if (marksSolidRows(piece.w)) {
            markSolidRows(obj, y, height, mask);
        }

        if ((unsigned int)(((int)piece.w >> 10) & 3) == 3) {
            switch ((int)((piece.w >> 6) & 0xf)) {
            case 3:
                ++variant3Count;
                break;
            case 6:
                ++variant6Count;
                break;
            case 7:
                ++variant7Count;
                break;
            case 9:
                obj->centers[centerY] |= 1 << centerX;
                break;
            default:
                break;
            }
        }
    }

    for (unsigned int i = 0; i < count; ++i) {
        pieceWord = pieces[i].w;
        if (fn_27_22D1D8(obj, 0, &pieceWord, obj->extended,
                         obj->rows, obj->columns) & 0x4000) {
            ++flaggedCount;
        }
    }

    obj->variant6Count = variant6Count;
    obj->variant3Count = variant3Count;
    obj->variant7Count = variant7Count;
    obj->extendedCount = extendedCount;
    obj->flaggedCount = flaggedCount;

    obj->runCount = countRuns(obj, obj->columns);
    obj->minX = minX;
    obj->minY = minY;
    obj->maxX = maxX;
    obj->maxY = maxY;
}
