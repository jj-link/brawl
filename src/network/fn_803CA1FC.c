#pragma force_active on
#include <types.h>

typedef struct Entry {
    int a;
    int (*b)(int, int, int);
    int c;
    int d;
} Entry;

extern Entry lbl_80563798[];
extern int lbl_805A1228;
extern int lbl_805A122C;

extern int *fn_803C4450(void);
extern u32 fn_803C7DE4(int);
extern void fn_803C7D64(int, int);
extern int fn_803C8B48(int, void *, int);
extern void fn_803A976C(void *, int, u32);
extern void fn_803C759C(void *);
extern int fn_803C7460(void *);
extern void fn_803C7CB8(int, u32);
extern u32 fn_803C7C64(int);
extern int fn_803C75FC(int, u32, int, int);
extern void fn_803C7DE8(int, int);
extern int fn_803C7684(int);
extern int fn_803C7698(int);
extern void fn_803C7E94(int, int);
extern void fn_803C7F40(int, int);
extern int fn_8020B9BC(int, int, int);
extern int fn_8020BA48(int, int, int);
extern int fn_8020BC3C(int);
extern void OSSleepTicks(s64);

#define RETRY_SLEEP() OSSleepTicks(lbl_805A122C * (s64)((*(u32 *)0x800000F8 / 4) / 1000))

int fn_803CA1FC(int arg0, int arg1) {
    u8 buf[32] __attribute__((aligned(64)));
    int *p;
    u32 idx;
    int count;
    int ret;
    int handle;
    int status;
    int sess;
    int ret2;

    p = fn_803C4450();
    idx = fn_803C7DE4(arg0);
    if (p == 0) return -0x14;
    handle = *p;

    if (idx < 0x1A) {
        if (lbl_80563798[idx].b != 0) {
            ret = lbl_80563798[idx].b(arg1, handle, 1);
        } else {
            ret = 0;
            count = lbl_805A1228;
            while (count-- > 0) {
                ret = fn_8020B9BC(arg1, handle, 1);
                switch (ret) { case -3: goto s1; }
                switch (ret) { case -2: goto s1; }
                break;
            s1:
                RETRY_SLEEP();
            }
        }
    } else if ((u32)(idx + 0x10000) == 0xFFF6) {
        ret = 0;
        count = lbl_805A1228;
        while (count-- > 0) {
            ret = fn_8020B9BC(arg1, handle, 1);
            switch (ret) { case -3: goto s2; }
            switch (ret) { case -2: goto s2; }
            break;
        s2:
            RETRY_SLEEP();
        }
    } else {
        ret = 0;
        count = lbl_805A1228;
        while (count-- > 0) {
            ret = fn_8020BA48(arg1, handle, 1);
            switch (ret) { case -3: goto s3; }
            switch (ret) { case -2: goto s3; }
            break;
        s3:
            RETRY_SLEEP();
        }
    }

    if (ret != 0) goto error;
    {
        fn_803A976C(buf, 0, 0x20);
        count = fn_803C8B48(handle, buf, 0x20);
        if (count < 0) {
            ret = lbl_805A1228;
            while (ret-- > 0) {
                int s;
                s = fn_8020BC3C(handle);
                switch (s) { case -3: goto s4; }
                switch (s) { case -2: goto s4; }
                break;
            s4:
                RETRY_SLEEP();
            }
            fn_803C7D64(arg0, count);
            return count;
        }

        fn_803C759C(buf);
        if (fn_803C7460(buf) == 0) {
            int count = lbl_805A1228;
            while (count-- > 0) {
                int s;
                s = fn_8020BC3C(handle);
                switch (s) { case -3: goto s5; }
                switch (s) { case -2: goto s5; }
                break;
            s5:
                RETRY_SLEEP();
            }
            return -1;
        }

        fn_803C7CB8(arg0, ((u32)buf[8] << 24) | ((u32)buf[9] << 16) | ((u32)buf[10] << 8) | (u32)buf[11]);
        sess = fn_803C75FC(0, ((u32)fn_803C7C64(arg0) - 0x1F) >> 9, 1, 0x200);
        fn_803C7DE8(arg0, sess);
        fn_803C7E94(arg0, fn_803C7684(sess));
        fn_803C7F40(arg0, fn_803C7698(sess));

        {
        int count = lbl_805A1228;
        while (count-- > 0) {
            int s;
            s = fn_8020BC3C(handle);
            switch (s) { case -3: goto s6; }
            switch (s) { case -2: goto s6; }
            break;
        s6:
            RETRY_SLEEP();
        }

        }
        goto open3;
    error:
        fn_803C7D64(arg0, ret);
        return ret;
    open3:
        if (idx < 0x1A) {
            if (lbl_80563798[idx].b != 0) {
                count = lbl_80563798[idx].b(arg1, handle, 3);
            } else {
                count = 0;
                ret = lbl_805A1228;
                while (ret-- > 0) {
                    count = fn_8020B9BC(arg1, handle, 3);
                    switch (count) { case -3: goto s7; }
                    switch (count) { case -2: goto s7; }
                    break;
                s7:
                    RETRY_SLEEP();
                }
            }
        } else if ((u32)(idx + 0x10000) == 0xFFF6) {
            count = 0;
            ret = lbl_805A1228;
            while (ret-- > 0) {
                count = fn_8020B9BC(arg1, handle, 3);
                switch (count) { case -3: goto s8; }
                switch (count) { case -2: goto s8; }
                break;
            s8:
                RETRY_SLEEP();
            }
        } else {
            count = 0;
            ret = lbl_805A1228;
            while (ret-- > 0) {
                count = fn_8020BA48(arg1, handle, 3);
                switch (count) { case -3: goto s9; }
                switch (count) { case -2: goto s9; }
                break;
            s9:
                RETRY_SLEEP();
            }
        }

        if (count == 0) return 0;
        fn_803C7D64(arg0, count);
        return count;
    }
}
