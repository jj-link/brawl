#pragma force_active on

extern int fn_803A685C(int, int *);
extern void *fn_803A6740(int, int);
extern void fn_803A6828(int, void *, int);
extern int fn_803A6944(int, int);
extern int fn_80213090(int, int, int, int, void *);
extern void *memcpy(void *, const void *, unsigned long);
extern void *memset(void *, int, unsigned long);
extern char *strcpy(char *, const char *);
extern int strlen(const char *);

typedef struct Request {
    char *name;
    int nameLen;
    char *desc;
    int descLen;
    char *data;
    int dataSize;
    void *pool;
    int poolSize;
} Request;

typedef struct Pool {
    unsigned char pad[0x18];
    int unk18;
    void *unk1C;
} Pool;

void fn_803A81A8(const char *name, const char *desc, const void *data, void **out)
{
    int handle;
    int result;
    Pool *pool;
    Request *request;
    char *str0;
    char *str1;
    char *buf;
    int total;
    int len;
    int ptr;

    if (fn_803A685C(0, &handle) == 0) {
        if (desc == 0) {
            len = 0;
        } else {
            len = strlen(name) + 1;
        }
        total = len;

        if (name == 0) {
            len = 0;
        } else {
            len = strlen(name) + 1;
        }
        total = ((((len + 0x1F) & ~31u) + ((total + 0x1F) & ~31u)) + 0x5F) & ~31u;

        request = fn_803A6740(12, total);
        if (request == 0) {
            result = -49;
        } else {
            pool = fn_803A6740(10, 0x840);
            if (pool == 0) {
                fn_803A6828(12, request, total);
                result = -49;
            } else {
                str0 = (char *)request + 0x20;
                if (name == 0) {
                    len = 0;
                } else {
                    len = strlen(name) + 1;
                }
                str1 = str0 + ((len + 0x1F) & ~31u);
                if (desc == 0) {
                    len = 0;
                } else {
                    len = strlen(name) + 1;
                }
                buf = str1 + ((len + 0x1F) & ~31u);

                if (name != 0) {
                    strcpy(str0, name);
                }
                request->name = (name != 0) ? str0 : 0;
                if (name == 0) {
                    len = 0;
                } else {
                    len = strlen(name);
                }
                request->nameLen = len;

                if (desc != 0) {
                    strcpy(str1, desc);
                }
                request->desc = (desc != 0) ? str1 : 0;
                if (desc == 0) {
                    len = 0;
                } else {
                    len = strlen(desc);
                }
                request->descLen = len;

                if (data != 0) {
                    memcpy(buf, data, 0x20);
                } else {
                    memset(buf, 0, 0x20);
                }

                if (((int *)buf)[1] == 0) {
                    ((int *)buf)[1] = 2;
                }

                if (((int *)buf)[1] == 0x17) {
                    *out = 0;
                    result = -68;
                    fn_803A6828(10, pool, 0x840);
                } else {
                    request->data = buf;
                    request->dataSize = 0x20;
                    request->pool = pool;
                    request->poolSize = 0x834;

                    result = fn_80213090(handle, 0x18, 3, 1, request);
                    if (result >= 0) {
                        *out = pool;
                        ptr = (int)((char *)pool + 0x460);
                        while (pool != 0) {
                            pool->unk18 = ptr;
                            if (pool->unk1C != 0) {
                                pool->unk1C = (void *)((char *)pool + 0x20);
                            }
                            pool = pool->unk1C;
                            ptr += 0x1C;
                        }
                    } else {
                        *out = 0;
                        fn_803A6828(10, pool, 0x840);
                    }
                }
                fn_803A6828(12, request, total);
            }
        }
        fn_803A6944(0, result);
    }
}
