/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the Wine project.
 */

#ifndef _WTIME_DEFINED
#define _WTIME_DEFINED

#include <corecrt.h>

struct tm {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
};

#ifdef _USE_32BIT_TIME_T
#define _wctime32 _wctime
#endif

#ifdef __cplusplus
extern "C" {
#endif

wchar_t* __cdecl _wasctime(const struct tm*);
size_t   __cdecl wcsftime(wchar_t*,size_t,const wchar_t*,const struct tm*);
wchar_t* __cdecl _wctime32(const __time32_t*);
wchar_t* __cdecl _wctime64(const __time64_t*);
wchar_t* __cdecl _wstrdate(wchar_t*);
errno_t  __cdecl _wstrdate_s(wchar_t*,size_t);
wchar_t* __cdecl _wstrtime(wchar_t*);
errno_t  __cdecl _wstrtime_s(wchar_t*,size_t);

#ifndef _USE_32BIT_TIME_T
static inline wchar_t* _wctime(const time_t *t) { return _wctime64(t); }
#endif

#ifdef __cplusplus
}
#endif

#endif /* _WTIME_DEFINED */