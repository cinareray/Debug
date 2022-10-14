#undef DEBUG_MODULE
#define DEBUG_MODULE DEBUG_MODULE_DEBUG

#include <stdarg.h>
#include <stdio.h>

#include <tim.h>
#include <inttypes.h>

#include "debug.h"	
#include "usart.h"

//struct timeval beg;
//struct timespec beg;

int debug_threshold = DEBUG_LEVEL_ASSERT; // DEFAULT SILENCE

int debug_init(void){
return 0;
}

int debug_process(void){
return 0;
}

void debug_uninit(void){
}

void debug_level_set(const int level){
	debug_threshold = level;
}

static const char *debug_level_get_string(const int level){
	if(level <= DEBUG_LEVEL_ASSERT){
		return "assert";}
	else if(level <= DEBUG_LEVEL_ERROR){
		return "error";}
	else if(level <= DEBUG_LEVEL_WARNING){
		return "warning";}
	else if(level <= DEBUG_LEVEL_INFO){
		return "info";}
	else if(level <= DEBUG_LEVEL_DEBUG){
		return "debug";}
	else if(level <= DEBUG_LEVEL_TRACE){
		return "trace";}
}

static const char *debug_module_get_string(const int module){
	switch(module){
		case 0 : return "debug"  ;
		case 1 : return "main"   ;
		case 2 : return "gnss"	 ;
		case 3 : return "vtc"		 ;
		case 4 : return "gsm"		 ;
		default: return "unknown";
	}
}

int debug_printf(const int debug_level, const int debug_module, const char* function, const char* file, const int line, const char *format,...){

	if(debug_level <= debug_threshold){

		fprintf(stdout,"[%"PRIu32":%03"PRIu32"] ",GetTimerSec()%3600,GetTimerMs()%1000);		
		fprintf(stdout,"%s:%s ",debug_level_get_string(debug_level),debug_module_get_string(debug_module));

		va_list va;
		va_start(va,format);
		vfprintf(stdout,format,va);
		va_end(va);

		fprintf(stdout," %s() %s:%d\n",function,file,line);
	}
	return 0;
}
