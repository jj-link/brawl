struct MarioArticlePoolEntry {
    unsigned char storage[0x1e54];
};
template <int Count> struct MarioArticlePool;
template <> struct MarioArticlePool<0> {
    unsigned char prefix[8];
    MarioArticlePoolEntry* get(int) { return 0; }
};
template <int Count> struct MarioArticlePool {
    unsigned char prefix[4];
    MarioArticlePool<Count - 1> previous;
    MarioArticlePoolEntry entry;
    MarioArticlePoolEntry* get(int index) {
        if (index == Count - 1) return &entry;
        return previous.get(index);
    }
};
extern "C" void* fn_91_141A0(MarioArticlePool<12>* pool, int index) {
    return pool->get(index);
}
