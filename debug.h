/*
 * =====================================================================================
 *
 *       Filename:  debug.h
 *
 *    Description:  Debug Library header
 *
 *        Version:  1.0
 *        Created:  18/10/2015 12:52:49
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Guillerme Duvillié (mfreeze), gduvillie@openmailbox.org
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef DEBUG_H
#define DEBUG_H

#define debug_file

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define OK 0
#define ERR -1

#define __enable_log_file FILE *_deb_logger = fopen("/tmp/log", "a");
#define __disable_log_file fclose(_deb_logger);

#define DEB_PRINT(...) do {\
__enable_log_file; \
    fprintf(_deb_logger, "DEBUG -- ");\
    fprintf(_deb_logger,##__VA_ARGS__);\
__disable_log_file; \
}while(0);

#define OL_DEB_PRINT(...) do {\
    fprintf(_deb_logger,##__VA_ARGS__);\
}while(0);

#define PRINTVAR(x) do {\
__enable_log_file; \
fprintf(_deb_logger, "DEBUG -- %s:%d " #x " = %d\n", __FILE__, __LINE__, x);\
__disable_log_file; \
} while(0);
#define OL_PRINTVAR(x) fprintf(_deb_logger, "%s:%d " #x " = %d\n", __FILE__, __LINE__, x);

#define PRINTSTR(x) fprintf(_deb_logger, "DEBUG -- %s:%d " #x " = %s\n", __FILE__, __LINE__, x);
#define OL_PRINTSTR(x) fprintf(_deb_logger, "%s:%d " #x " = %s\n", __FILE__, __LINE__, x);
#endif
