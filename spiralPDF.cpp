/* Christian Purdy
 * CS3505
 * A2 Classes & Facades
*/
#include "haruPDF.h"
#include "Spiral.h"

// argc is the number of arguments. Argv is an array of character arrays, or C-style strings.
// If you call the program like ./pdfExample "Hello", then argv[1] would contain "Hello\0".
// argv[0] would be "pdfExample\0" - the name of the executing program.
int main (int argc, char **argv)
{

	double xStart = 200;
	double yStart = 310;
	double radStart = 50;

//checks to make sure there are more than 1 arguments from command line, the 2nd argument
//is the text to make into a spiral

	int argNum = argc;
	if(argNum < 2) 
	{
		std :: cout << "Give text to make spiral" << std :: endl;
		return 0;
	}

	Spiral spiral(xStart, yStart, radStart);
	HaruPDF pdf(argv[0]);

	char words[256];

	//copy arguments to string
	strcpy (words, argv[1]);

	int len = strlen(words);
	//length of words to be spiralled
	for(int i = 0; i < len; i++) 
	{
		char c = words[i];
		spiral.movePosition();
		pdf.writePDF(spiral.getTextX(),spiral.getTextY(),spiral.getTextAngle(), c);
		
		

	}
	//save file	
	pdf.save();
	return 0;
}
