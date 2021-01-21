#include "Log.h" // Literally include (as in copying) the content from the headers.h file directly into this

// When including your header files, add the .h extension and pass the path to the header file, exs: "Log.h", "../Common.h", "./headers/Special.h"
// When including header files from your 'includes' folder (the default location for the standard C++ library in your computer), you just pass the name of the header with angular brackets in it's sides: <iostream>, <string>
// When including C header files from your 'includes' folder, you pass the name of the header with angular brackets and a .h extension at the end in it's sides: <stdlib.h>

void ExecuteHeaders()
{
    Log("Executing function Log with declaration coming from headers.h");
}
