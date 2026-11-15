
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
#pragma force_active on
typedef struct Work Work;
typedef struct Ref
{
  int key;
  int count;
} Ref;
struct Work
{
  int state;
  int pad4;
  void *list;
  char padC[0x70];
  char *buffer;
  int length;
  int keys[255];
  int count;
  int current;
  void (*callback)(Work *, int, int, int);
  char pad48C[8];
  int userdata;
  char pad498[0x218];
  char *message;
  int socket;
};
extern int send(int, const void *, unsigned long, int);
extern int closesocket(int);
extern void fn_8035E00C(void *);
extern int fn_8035A590(void *);
extern int *fn_8035A598(void *, int);
extern void fn_8035A4FC(void *);
extern void *fn_80388590(Work *);
extern Ref *fn_8035B1C4(void *, int *);
extern void fn_8035B120(void *, int *);
extern int fn_8038A904(Work *, int, int, int, int);
extern char *lbl_8059FBCC;
extern int lbl_805A1128;
int fn_8038A574(Work *self, const void *data, int length)
{
  int result;
  int sent;
  int retries;
  for (retries = 1; retries >= 0;)
  {
    int *p;
    --retries;
    sent = send(self->socket, data, length, 0);
    if ((sent > 0) || (retries < 0))
    {
      break;
    }
    {
      int key2[2];
      int key1[2];
      int i;
      int *p;
      Ref *ref;
      if (self->buffer)
      {
        fn_8035E00C(self->buffer);
      }
      self->buffer = 0;
      self->length = 0;
      if (self->socket != (-1))
      {
        closesocket(self->socket);
      }
      self->socket = -1;
      self->state = 1;
      if (self->list)
      {
        for (i = 0; i < fn_8035A590(self->list); ++i)
        {
          key1[0] = *fn_8035A598(self->list, i);
          ref = fn_8035B1C4(fn_80388590(self), &key1[0]);
          if (ref && ((--ref->count) == 0))
          {
            fn_8035B120(fn_80388590(self), &key1[0]);
          }
        }

        fn_8035A4FC(self->list);
        self->list = 0;
      }
      self->current = -1;
      p = (int *) self;
      for (i = 0; i < self->count; ++i)
      {
        key2[0] = p[0x21];
        ref = fn_8035B1C4(fn_80388590(self), &key2[0]);
        if (ref && ((--ref->count) == 0))
        {
          fn_8035B120(fn_80388590(self), &key2[0]);
        }
        ++p;
      }

      self->count = 0;
    }
    result = fn_8038A904(self, 0, 0, 2, 0);
    if (result)
    {
      int n = self->length;
      if (n > 0)
      {
        char *prefix = lbl_8059FBCC;
        if (((unsigned int) n) > strlen(prefix))
        {
          char *prefix2 = lbl_8059FBCC;
          char *buffer = self->buffer;
          if (strncmp(buffer, prefix2, strlen(prefix2)) == 0)
          {
            self->message = buffer + strlen(prefix);
            self->callback(self, 5, lbl_805A1128, self->userdata);
          }
        }
      }
      self->callback(self, 4, lbl_805A1128, self->userdata);
      {
        int key1[2];
        int key2[2];
        int i;
        Ref *ref;
        if (self->buffer)
        {
          fn_8035E00C(self->buffer);
        }
        self->buffer = 0;
        i = self->socket;
        self->length = 0;
        if (i != (-1))
        {
          closesocket(i);
        }
        self->socket = -1;
        self->state = 1;
        if (self->list)
        {
          for (i = 0; i < fn_8035A590(self->list); ++i)
          {
            key1[0] = *fn_8035A598(self->list, i);
            ref = fn_8035B1C4(fn_80388590(self), &key1[0]);
            if (ref && ((--ref->count) == 0))
            {
              fn_8035B120(fn_80388590(self), &key1[0]);
            }
          }

          fn_8035A4FC(self->list);
          self->list = 0;
        }
        p = (int *) self;
        self->current = -1;
        for (i = 0; i < self->count; ++i)
        {
          key2[0] = p[0x21];
          ref = fn_8035B1C4(fn_80388590(self), &key2[0]);
          if (ref && ((--ref->count) == 0))
          {
            fn_8035B120(fn_80388590(self), &key2[0]);
          }
          ++p;
        }

        self->count = 0;
      }
      return result;
    }
  }

  {
    int status = 0;
    if (sent <= 0)
    {
      status = 3;
    }
    return status;
  }
}
