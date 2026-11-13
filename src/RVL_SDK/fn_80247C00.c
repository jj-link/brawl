#pragma force_active on

typedef enum _va_arg_type
{
  arg_ARGPOINTER,
  arg_WORD,
  arg_DOUBLEWORD,
  arg_ARGREAL
} _va_arg_type;
typedef struct __va_list_struct
{
  char gpr;
  char fpr;
  char *input_arg_area;
  char *reg_save_area;
} va_list[1];
void *__va_arg(va_list argp, int type);
typedef signed long intptr_t;
typedef unsigned long uintptr_t;
typedef intptr_t ptrdiff_t;
typedef unsigned long size_t;
typedef unsigned short wchar_t;
typedef unsigned long long u64;
typedef signed long long s64;
typedef unsigned long u32;
typedef signed long s32;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char u8;
typedef signed char s8;
typedef float f32;
typedef double f64;
typedef int UNKWORD;
typedef void UNKTYPE;
enum 
{
  FALSE,
  TRUE
};
typedef int BOOL;
typedef void (*funcptr_t)(void);
int stricmp(const char *, const char *);
char *itoa(int value, char *str, int base);
void *memcpy(void *, const void *, size_t);
void *memset(void *, int, size_t);
void *memfill(const void *, int, size_t);
void *__memfill(const void *, int, size_t);
void *memmove(void *, const void *, size_t);
void *memchr(const void *, int, size_t);
void *__memrchr(const void *, int, size_t);
int memcmp(const void *, const void *, size_t);
char *strcpy(char *, const char *);
char *strncpy(char *, const char *, size_t);
char *strcat(char *, const char *);
char *strncat(char *, const char *, size_t);
int strcmp(const char *, const char *);
int strncmp(const char *, const char *, size_t);
char *strchr(const char *, int);
char *strstr(const char *, const char *);
size_t strlen(const char *);
typedef struct Entry
{
  unsigned char used;
  unsigned char addr[6];
  unsigned char pad;
  unsigned short value;
  unsigned char a;
  unsigned char pad2;
  unsigned char b;
  unsigned char rest[39];
} Entry;
extern Entry lbl_8052C9B8[];
extern int fn_803F6150(const void *, const void *, unsigned long);
int fn_80247C00(const void *addr, unsigned short value, unsigned char *out)
{
  unsigned char **new_var;
  unsigned char *p = (unsigned char *) lbl_8052C9B8;
  int i;
  new_var = &p;
  if (!((unsigned char *) lbl_8052C9B8)[0x400])
  {
    return 1;
  }
  for (i = 0; i < 16; i++, p += 52)
  {
    if (fn_803F6150(addr, (*new_var) + 1, 6) == 0)
    {
      break;
    }
  }

  if (i == 16)
  {
    Entry *q = lbl_8052C9B8;
    for (i = 0; i < 16; q++, i++)
    {
      if (!q->used)
      {
        break;
      }
    }

  }
  if (i == 16)
  {
    return 3;
  }
  if (!lbl_8052C9B8[i].used)
  {
    lbl_8052C9B8[i].used = 1;
    memcpy(lbl_8052C9B8[i].addr, addr, 6);
    lbl_8052C9B8[i].a = 0;
    lbl_8052C9B8[i].b = 0;
  }
  lbl_8052C9B8[i].value = value;
  *out = i;
  return 0;
}
