#pragma force_active on
typedef struct Obj {
    int fd;
    int addr;
    unsigned short port;
    char padA[2];
    int table;
    int list;
    char pad14[0x10];
    int field24;
    char pad28[0x10];
    int field38;
    int field3C;
    int field40;
    int field44;
    int field48;
} Obj;
typedef struct Addr {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    int addr;
} Addr;
extern void fn_8035D720(void);
extern int fn_803789AC(char *, int *, unsigned short *);
extern void *fn_8035DFE8(int);
extern void fn_8035E00C(void *);
extern void *memset(void *, int, unsigned long);
extern int fn_8035AED0(int, int, int, void *, void *, void *);
extern int fn_8035A460(int, int, void *);
extern void fn_8035AF74(int);
extern void fn_8035A4FC(int);
extern void fn_80377D34(void);
extern void fn_80377D54(void);
extern void fn_80377D88(void);
extern int socket(int, int, int);
extern int bind(int, void *, int);
extern int closesocket(int);
extern int getsockname(int, void *, int *);
extern unsigned short SOHtoNs(unsigned short);
extern unsigned short SONtoHs(unsigned short);

int fn_80377DDC(Obj **out, char *name, int a, int b, int c, int mode) {
    unsigned short port;
    int addr;
    int len;
    Addr sa;
    Obj *obj;
    int result;

    fn_8035D720();
    if (b == 0) b = 0x10000;
    if (a == 0) a = 0x10000;
    if (!fn_803789AC(name, &addr, &port)) return 4;
    obj = fn_8035DFE8(0x4c);
    if (!obj) return 1;
    memset(obj, 0, 0x4c);
    obj->fd = -1;
    obj->field3C = b;
    obj->field38 = a;
    obj->field24 = c;
    result = fn_8035AED0(4, 0x20, 2, fn_80377D34, fn_80377D54, 0);
    obj->table = result;
    if (!result) {
        fn_8035E00C(obj);
        return 1;
    }
    result = fn_8035A460(4, 4, fn_80377D88);
    obj->list = result;
    if (!result) {
        fn_8035AF74(obj->table);
        fn_8035E00C(obj);
        return 1;
    }
    obj->fd = socket(2, 2, 0x11);
    obj->field40 = mode;
    if (mode == 3) obj->field44 = 0;
    else obj->field44 = mode;
    if (obj->fd == -1) {
        fn_8035AF74(obj->table);
        fn_8035A4FC(obj->list);
        fn_8035E00C(obj);
        return 3;
    }
    memset(&sa, 0, 8);
    sa.family = 2;
    sa.addr = addr;
    sa.port = SOHtoNs(port);
    if (mode != 3) mode = bind(obj->fd, &sa, 8);
    if (mode == -1) {
        closesocket(obj->fd);
        fn_8035AF74(obj->table);
        fn_8035A4FC(obj->list);
        fn_8035E00C(obj);
        return 3;
    }
    len = 8;
    getsockname(obj->fd, &sa, &len);
    obj->addr = sa.addr;
    obj->port = SONtoHs(sa.port);
    *out = obj;
    return 0;
}