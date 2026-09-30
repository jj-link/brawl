// Tail-call entry point for _fseek.
struct FILE;
extern int _fseek(struct FILE*, long, int);

int fn_803F5EA8(struct FILE* stream, long offset, int origin) {
    return _fseek(stream, offset, origin);
}
