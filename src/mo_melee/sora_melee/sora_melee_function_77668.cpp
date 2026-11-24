#pragma force_active on

struct Pool {
    void* data;
    short* links;
    short freeHead;
    short count;
    int other[2];
};

extern Pool lbl_27_bss_2BEC;

struct List {
    int unknown;
    short head;
};

inline void append(Pool* pool, short cur, short index) {
    if (cur >= 0) {
        do {
            do {
                short prev = cur;
                cur = pool->links[prev];
                if (cur < 0) {
                    pool->links[prev] = index;
                    return;
                }
            } while (cur >= 0);
        } while (true);
    }
}

inline short allocate(Pool* pool, short cur, short index) {
    if (index <= -1)
        return -1;

    short* links = pool->links;
    pool->freeHead = links[index];
    links[index] = -2;

    append(pool, cur, index);
    return index;
}

extern "C" void fn_27_77668(List* list, const unsigned int* src) {
    Pool* pool = &lbl_27_bss_2BEC;
    short cur = list->head;
    short index = pool->freeHead;

    index = allocate(pool, cur, index);
    if (index >= 0) {
        unsigned int* dst =
            (unsigned int*)((char*)lbl_27_bss_2BEC.data + index * 16);

        if (dst != src) {
            if (dst != src) {
                if (dst + 1 != src + 1)
                    dst[1] = src[1];
                dst[2] = src[2];
                dst[3] = src[3];
                if (dst[2] == 0)
                    dst[3] = 0;
            }
        }

        if (list->head < 0)
            list->head = index;
    }
}
