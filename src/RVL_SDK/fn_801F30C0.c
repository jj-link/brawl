#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct { u32 image1; u32 image2; u32 pad; u8 is32b; u8 isCached; } GXTexRegion;

void GXInitTexCacheRegion(GXTexRegion* region, u8 is32b, u32 tmemEven, int sizeEven, u32 tmemOdd, int sizeOdd) {
    u32 w = sizeEven;
    u32 img = 0;
    switch (sizeEven) {
        case 0: w = 3; break;
        case 1: w = 4; break;
        case 2: w = 5; break;
    }
    img = __rlwimi(img, tmemEven, 27, 17, 31);
    img = __rlwimi(img, w, 15, 14, 16);
    img = __rlwimi(img, w, 18, 11, 13);
    region->image1 = img;
    switch (sizeOdd) {
        case 0: w = 3; break;
        case 1: w = 4; break;
        case 2: w = 5; break;
        case 3: w = 0; break;
    }
    img = 0;
    img = __rlwimi(img, tmemOdd, 27, 17, 31);
    img = __rlwimi(img, w, 15, 14, 16);
    img = __rlwimi(img, w, 18, 11, 13);
    region->is32b = is32b;
    region->image2 = img;
    region->isCached = 1;
}
