#pragma force_active on
typedef unsigned int u32;
typedef long long s64;
typedef struct { void *handle; char pad[0x38]; char data[1]; } Obj;
typedef struct { char pad[12]; u32 type; } Info;
typedef struct { Info *info; } Wrapper;
typedef struct { void *a; int (*b)(void *, void *, int); void *c; void *d; } Entry;
extern int lbl_805A1228, lbl_805A122C;
extern Entry lbl_80563798[];
extern Obj *fn_803C4410(u32);
extern Wrapper *fn_803C42AC(u32);
extern int fn_8020BC3C(void *);
extern int fn_8020B9BC(void *, void *, int);
extern int fn_8020BA48(void *, void *, int);
extern void fn_803C7DBC(u32, int);
extern void OSSleepTicks(s64);
int fn_803C9ED8(u32 arg0, int arg1) {
    Obj *obj = fn_803C4410(arg0);
    Wrapper *p = fn_803C42AC(arg0);
    int status, count;
    void *data, *handle;
    if (p && p->info && p->info->type == 1) return 0;
    if (obj) {
        handle = obj->handle;
        data = obj->data;
        count = lbl_805A1228;
        status = 0;
        while (count-- > 0) {
            status = fn_8020BC3C(handle);
            switch (status) { case -3: goto sleep0; }
            switch (status) { case -2: goto sleep0; }
            break;
sleep0:
            OSSleepTicks(lbl_805A122C * (s64)((*(u32 *)0x800000F8 / 4) / 1000));
        }
        if (status < 0) {
            if (arg1) fn_803C7DBC(arg0, status);
            return status;
        }
        if (arg0 < 26) {
            if (lbl_80563798[arg0].b) {
                status = lbl_80563798[arg0].b(data, handle, 3);
            } else {
                int count = lbl_805A1228;
                status = 0;
                while (count-- > 0) {
                    status = fn_8020B9BC(data, handle, 3);
                    switch (status) { case -3: goto sleep1; }
            switch (status) { case -2: goto sleep1; }
            break;
sleep1:
                    OSSleepTicks(lbl_805A122C * (s64)((*(u32 *)0x800000F8 / 4) / 1000));
                }
            }
        } else if (arg0 == (u32)-10) {
            int count = lbl_805A1228;
            status = 0;
            while (count-- > 0) {
                status = fn_8020B9BC(data, handle, 3);
                switch (status) { case -3: goto sleep2; }
            switch (status) { case -2: goto sleep2; }
            break;
sleep2:
                OSSleepTicks(lbl_805A122C * (s64)((*(u32 *)0x800000F8 / 4) / 1000));
            }
        } else {
            int count = lbl_805A1228;
            status = 0;
            while (count-- > 0) {
                status = fn_8020BA48(data, handle, 3);
                switch (status) { case -3: goto sleep3; }
            switch (status) { case -2: goto sleep3; }
            break;
sleep3:
                OSSleepTicks(lbl_805A122C * (s64)((*(u32 *)0x800000F8 / 4) / 1000));
            }
        }
        if (status < 0) {
            if (arg1) fn_803C7DBC(arg0, status);
            return status;
        }
    }
    return 0;
}