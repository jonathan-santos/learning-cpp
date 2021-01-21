#pragma once // Basically makes this Header file only be copied ONCE in a translation unit (.obj binary file)
// Unless you really know what you are doing, always put #pragma once in your files

/* the following was the old way of preventing this problem:
#ifndef _LOG_H //On the first line of file
#define LOG_H // On the second line of file
#endif // On the end of file
*/

void Log(const char* message);
