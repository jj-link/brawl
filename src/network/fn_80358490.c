#pragma force_active on
typedef struct { char a[0x22]; char b[0x64]; short end; char c[11], d[11], e[11]; char pad; int number; } Entry;
typedef struct { char pad[12]; Entry *entries; int count; } Context;
extern char lbl_8048E650[];
extern void *memset(void *, int, unsigned long);
extern int fn_803968E4(void *, const char *, char **);
extern int fn_803960EC(void *, char **, int *);
extern void fn_8034F028(void *, const void *, unsigned int);
extern unsigned int fn_803568D0(void *, const char *, int);
extern int fn_80392AB8(const char *, int);
int fn_80358490(void *arg0, Context *ctx) {
 char *body;
 int ignored;
 char *value;
 double buffer[13];
 int size, i, pos, field, start, cr, n;
 int result = 0;
 unsigned int len;
 Entry *entry;
 memset(ctx->entries, 0, ctx->count * 0xb0);
 if (fn_803968E4(arg0, lbl_8048E650, &value) > 0 && value[0] == '0' && value[1] == 0) return 1;
 size = fn_803960EC(arg0, &body, &ignored);
 if (size > 0) {
  pos = 0;
  for (i = 0; i < ctx->count; i++) {
   if (pos >= size) { result = 1; break; }
   entry = &ctx->entries[i];
   start = pos;
   field = 0;
   cr = 0;
   result = 0;
   while (pos < size) {
    if (body[pos] == '\r') { cr = 1; }
    else if (cr) {
     if (body[pos] == '\n') {
      if (field == 5) {
       if (pos - 1 - start > 8) goto done;
       n = fn_80392AB8(body + start, pos - 1 - start);
       if (n < 0) goto done;
       entry->number = n;
      }
      pos++;
      result = field >= 5;
      break;
     }
     goto reset;
    } else {
     if (body[pos] == '\t') {
      switch (field) {
       case 0:
        if ((unsigned int)(pos-start) > 0x20) goto done;
        fn_8034F028(entry->a, body+start, pos-start); break;
       case 1:
        n = pos-start;
        if ((unsigned int)((n & ~3) - (n >> 2)) > 0x66) goto done;
        len = fn_803568D0(buffer, body+start, n);
        fn_8034F028(entry->b, buffer, len > 0x66 ? 0x66 : len);
        entry->end = 0; break;
       case 2:
        if ((unsigned int)(pos-start) > 10) goto done;
        fn_8034F028(entry->c, body+start, pos-start); break;
       case 3:
        if ((unsigned int)(pos-start) > 10) goto done;
        fn_8034F028(entry->d, body+start, pos-start); break;
       case 4:
        if ((unsigned int)(pos-start) > 10) goto done;
        fn_8034F028(entry->e, body+start, pos-start); break;
       case 5:
        if (pos-start > 8) goto done;
        n = fn_80392AB8(body+start, pos-start);
        if (n < 0) goto done;
        entry->number = n; break;
      }
      field++;
      start = pos+1;
     }
reset:
     cr = 0;
    }
    pos++;
   }
  }
 }
done:
 return result;
}