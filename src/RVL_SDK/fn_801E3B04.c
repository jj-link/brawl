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
extern char lbl_80474DC8[];
extern s32 fn_8020A784(void *, u8, u8);
extern s32 fn_8020BA48(char *, void *, s32);
extern s32 fn_80211080(void);
extern s32 fn_80211720(void *);
extern s32 fn_8020AB58(void *, void *, s32);
extern s32 fn_8020BC3C(void *);
s32 fn_801E3B04(void)
{
  u8 file[0x90];
  u8 buffer[0x20] __attribute__((aligned(32)));
  s32 new_var;
  s32 result;
  s32 opened;
  new_var = (opened = 0);
  result = fn_8020A784(lbl_80474DC8, 0x3f, new_var);
  if ((result == 0) || (result == (-6)))
  {
    result = fn_8020BA48(lbl_80474DC8, file, 2);
    if (result == 0)
    {
      opened = 1;
      result = fn_80211080();
      if (result == 0)
      {
        memset(buffer, 0, 0x20);
        result = fn_80211720(buffer);
        if (result == 0)
        {
          result = fn_8020AB58(file, buffer, 0x20);
          if (result >= 0)
          {
            if (result != 0x20)
            {
              result = -8;
            }
            else
            {
              result = 0;
            }
          }
        }
      }
    }
  }
  if (opened)
  {
    fn_8020BC3C(file);
  }
  if (result == 0)
  {
    return 1;
  }
  return 0;
}
