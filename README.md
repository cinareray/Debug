# Usage 
First include in your project. 

The module name must be added to the enum. For instance my GNSS modul.

```C
enum{
	DEBUG_MODULE_DEBUG	    = 0,
	DEBUG_MODULE_MAIN	    = 1,      
	DEBUG_MODULE_GNSS       = 2,        /*this modul is my gnss modul*/
	DEBUG_MODULE_VTC	    = 3,
	DEBUG_MODULE_GSM	    = 4,
	DEBUG_MODULE_SHEHRAZAT  = 5,
    #define DEBUG_MODULE_DEBUG      DEBUG_MODULE_DEBUG
    #define DEBUG_MODULE_MAIN       DEBUG_MODULE_MAIN
    #define DEBUG_MODULE_GNSS       DEBUG_MODULE_GNSS
    #define DEBUG_MODULE_VTC 		DEBUG_MODULE_VTC
    #define DEBUG_MODULE_GSM		DEBUG_MODULE_GSM
    #define DEBUG_MODULE_SHEHRAZAT	DEBUG_MODULE_SHEHRAZAT
};
```

Then, your module should be modified to include the following ;

```C
#undef DEBUG_MODULE
#define DEBUG_MODULE DEBUG_MODULE_GNSS
```

Finally you must be set debug level in your code.

```C
debug_level_set(DEBUG_LEVEL_INFO);   /*my code set up as DEBUG_LEVEL_INFO*/
```





## Example

```C
/*...*/
#include "debug.h"

#undef DEBUG_MODULE
#define DEBUG_MODULE DEBUG_MODULE_MAIN

#define FirmWare 5
int main(){


    debug_level_set(DEBUG_LEVEL_INFO);
    debug_info("********************Version: %d********************", FirmWare);
    while(1){
        /*...*/
    }

}     
```

Output ; 

```
[4:588] info:main ********************Version: 5******************** main() ../main.c:11
```


  
