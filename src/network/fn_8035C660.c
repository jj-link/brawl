#pragma force_active on
typedef struct { int fd; int events; int revents; } Poll;
extern int fn_803A7838(Poll *, int, long long);
int fn_8035C660(int fd, int *readable, int *writable, int *error) {
    Poll p;
    int result;
    p.fd = fd;
    p.events = 0;
    if (readable) p.events |= 1;
    if (writable) p.events |= 8;
    p.revents = 0;
    result = fn_803A7838(&p, 1, 0);
    if (result < 0) return -1;
    if (readable) {
        if (result > 0 && (p.revents & 0x41)) *readable = 1;
        else *readable = 0;
    }
    if (writable) {
        if (result > 0 && (p.revents & 8)) *writable = 1;
        else *writable = 0;
    }
    if (error) {
        if (result > 0 && (p.revents & 0x20)) *error = 1;
        else *error = 0;
    }
    return result;
}