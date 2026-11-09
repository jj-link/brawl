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
extern char lbl_8047E8D0[];
extern unsigned char lbl_804FB4A0[];
extern char lbl_8059ED90[6];
extern void fn_8022E928(const char *, ...);
extern void fn_801D8690(const char *, int, const char *, ...);
extern unsigned char *fn_8022C980(void *);
extern unsigned char *fn_8022CA58(void);
void fn_8022DDBC(unsigned char *arg)
{
  char *strings = lbl_8047E8D0;
  unsigned char *p;
  unsigned char *entry;
  unsigned char *scan;
  unsigned char **new_var;
  unsigned char *global = lbl_804FB4A0;
  int i;
  switch (arg[0])
  {
    case 1:
      fn_8022E928(strings + 0xC64);
      p = arg + 2;
      new_var = &scan;
      for (i = 0; i < arg[1]; p += 0x16, i++)
    {
      entry = fn_8022C980(p);
      fn_8022E928(strings + 0xC84, p[0], p[1], p[2], p[3], p[4], p[5]);
      fn_8022E928(strings + 0xCB0, p[6], p[7], p[8], p[9], p[10], p[11], p[12], p[13], p[14], p[15], p[16], p[17], p[18], p[19], p[20], p[21]);
      if (entry == 0)
      {
        fn_8022E928(strings + 0xD0C);
        entry = fn_8022CA58();
        if (entry == 0)
        {
          scan = global;
          for (i = 0; i < 6; scan += 0x60, i++)
          {
            if ((*new_var)[0x4FD] == 0)
            {
              entry = (scan = global + (i * 0x60), (*new_var) + 0x4A4);
              break;
            }
          }

        }
        if (entry != 0)
        {
          entry[0x5C] = 1;
          entry[0x59] = 1;
          memcpy(entry + 0x40, p, 6);
          memcpy(entry + 0x46, p + 6, 16);
        }
      }
      else
      {
        memcpy(entry + 0x40, p, 6);
        memcpy(entry + 0x46, p + 6, 16);
        if (entry[0x5C] == 2)
        {
          entry[0x5C] = 3;
        }
        memcpy(global + 0x6FC, p, 6);
        fn_8022E928(strings + 0xD30, global[0x6FC], global[0x6FD], global[0x6FE], global[0x6FF], global[0x700], global[0x701]);
      }
    }

      break;

    case 2:
      fn_8022E928(strings + 0xD58);
      fn_8022E928(strings + 0xD7C, arg[1], *((unsigned short *) (arg + 2)), *((unsigned short *) (arg + 4)));
      global[0xE] = 0;
      break;

    case 3:
      fn_8022E928(strings + 0xDA8);
      fn_8022E928(strings + 0xDCC, arg[1], arg[2]);
      global[0xE] = 0;
      break;

    case 4:
      fn_8022E928(strings + 0xDE8);
      fn_8022E928(strings + 0xDCC, arg[1], *((unsigned short *) (arg + 2)));
      if ((*((unsigned short *) (arg + 2))) == 0)
    {
      fn_8022E928(strings + 0xE0C);
    }
      global[0xE] = 0;
      break;

    default:
      fn_801D8690(lbl_8059ED90, 0x1114, strings + 0xE2C);
      break;

  }

}
