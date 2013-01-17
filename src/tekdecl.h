/*
** This header provides definitions, constants, and various constructs that are used throughout the engine.
**
** Please read the comments as they will be used here to define a STANDARD coding convention that should be used
** THROUGHOUT THE ENTIRE ENGINE.
**
**
** Since Doxygen is used for documentation generation, each header file should follow these quick rules for documentation:
**
** A body documentation (i.e. documenting a function, variable, etc.) should use three slashes on 3 or more consecutive lines. For example:
**	/// 
**	/// Hello, this is a description of my object.
**	///
** 
** All descriptions of major bodies (classes, interfaces, functions, macros, and structures) should provide a brief and detailed description.
** The first sentence of each comment is automatically used as the brief. Be sure to keep this in mind when writing the description. For example:
**
**    	///
**	/// Obtains the user's id. Obtains the user's id if it exists. If it does not exist, an error will be thrown.
**	///
**
**
** When documenting member variables (public or private), the following syntax should be used:
**	int x; //!< The x-position of the object.
** 
** When documenting parameters of functions, the following tag should be used:
** 	\param x The x-position of the object.
**
** When describing what a function returns, the following tag should be used:
**	\return Returns the x-position of the object.
**
**
** 1. Inclusion Guards
**	When creating a new header file, inclusion guards should always be used!!
**	First, a #pragma once statement should be used, following by standard inclusion guards.
**	The inclusion guard name should be: _TEKSTORM_<FILENAME>_H
**	The filename entire macro should be in all caps.
**
** 2. Functions
**	All functions should use standard word casing, and all words should be spelled out (space permitting).
**	The name of the function should be descriptive of what that function does, and should be a verb.
**	For example: GetGraphicsDevice(), GetUserName(), CreateObject(), etc.
**	If Acronyms must be used, then all letters in the acronym are to be capitalized.
**	Example: void GUICreateWindow()
**
**	Parameter names should always be present, both in the header and the source.
**	They should be descriptive of what the argument is that is expected.
**	The name should use camel casing and should never be a verb.
**	Example: void GUICreateWindow(int x, int y, int style, int oldStyle)
**
** 3. Variables
**	Variables should use camel casing wherever possible, and should spell out words completely (space permitted).
**	Acronyms should be all caps. If the acronym is the first word, it should be all lower case.
**	Example: int guiStyle;
**
** 4. Classes
**	4.1. Class names
**		A class name should use standard word casing and should follow the same naming conventions as section 2 (functions).
**	4.2. Methods/Member functions
**		Private member function should use camel casing: that is, the first word should be lowercase.
**		For example: initializeData()
**		Public member functions should use the same convention as that in section 2 (functions).
**		Parameter conventions are defined in section 2 (functions).
**	4.3. Member Variables
**		Private member variables should follow the rules as outlined in section 3 ( variables )
**		Public member variables should also follow the rules as outlined in section 3, however,
**		they should use normal word casing. Example: int BufferSize;
** 5. Interfaces
**	Interfaces should be pure abstract classes (all functions are pure virtual)
**	5.1. Interface names
**		Interface names should follow the same rules as 4.1; however, they should always begin with the capital letter "I".
**		Example: IGraphicsDriver
**
**		If the interface is not truly an interface (i.e. at least one of the functions is pre-written, then normal class rules **		apply)
**
**	5.2. See 4.2
**	5.3. See 4.3
**
** 6. Global Variables
**	All global VARIABLES (not constants) should be preceded by an underscore (_). Example: int _defaultDevice.
**	This does not apply to static members of classes (see 4.3).
** 7. Constants
**	Global constants should be in all caps. Example: int DEFAULT_DEVICE;
**	If a constant is in a parameter or local variable, then it should follow rules 2 and 3 respectively.
** 8. Macros
**	Macros should be in all caps. Example: #define MIN(x,y) (x < y ? x : y)
** 
*/
#pragma once
#ifndef _TEKSTORM_TEKDECL_H



// forward declaration of standard namespaces
namespace Tekstorm
{
	namespace Core {}
	namespace Audio {}
	namespace Content {}
	namespace Graphics {}
	namespace IO {}
	namespace Math {}
	namespace Physics {}
	namespace Scene {}
	namespace Scripting {}
	namespace Networking {}
}




#endif /* _TEKSTORM_TEKDECL_H */
