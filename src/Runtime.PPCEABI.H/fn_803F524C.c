// Public fread entry forwards to the stream implementation.
struct FILE;
extern unsigned long fn_803F5250(void*, unsigned long, unsigned long, struct FILE*);

unsigned long fn_803F524C(void* buffer, unsigned long size, unsigned long count, struct FILE* stream) {
    return fn_803F5250(buffer, size, count, stream);
}
