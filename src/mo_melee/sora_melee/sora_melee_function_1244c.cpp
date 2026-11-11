#pragma force_active on
struct Mat { float m[3][4]; };
extern "C" void fn_80162894(Mat*);
static inline Mat fetch(void* p, int index) {
    void** arr = *(void***)p;
    return *(Mat*)((char*)arr[index] + 0xDC);
}
static inline Mat fetch2(void* p, int index) {
    if ((int)*(unsigned char*)((char*)*(void**)p + 0x57) != 5) {
        void** arr = **(void****)p;
        return *(Mat*)((char*)arr[index] + 0xDC);
    } else {
        void* d = *(void**)((char*)p + 4);
        if (d) {
            void** arr = *(void***)d;
            return *(Mat*)((char*)arr[index] + 0xDC);
        } else {
            Mat tmp;
            fn_80162894(&tmp);
            return tmp;
        }
    }
}
static inline void put(void* p, int index, Mat result) {
    void** arr = *(void***)p;
    *(Mat*)((char*)arr[index] + 0xDC) = result;
}
static inline void put2(void* self, int index, const Mat& result) {
    void* p2 = *(void**)((char*)self + 0x2C);
    if (!p2) return;
    if ((int)*(unsigned char*)((char*)*(void**)p2 + 0x57) != 5)
        put(*(void**)p2, index, result);
    else {
        void* d = *(void**)((char*)p2 + 4);
        if (d) put(d, index, result);
    }
}
extern "C" void fn_27_1244C(void* self, int index, float* vec) {
    Mat result;
    if (*(void**)((char*)self + 0x28))
        result = fetch(*(void**)((char*)self + 0x28), index);
    else if (*(void**)((char*)self + 0x2C))
        result = fetch2(*(void**)((char*)self + 0x2C), index);
    result.m[0][3] = vec[0];
    result.m[1][3] = vec[1];
    result.m[2][3] = vec[2];
    void* p1 = *(void**)((char*)self + 0x28);
    if (p1) {
        put(p1, index, result);
    } else {
        put2(self, index, result);
    }
}
