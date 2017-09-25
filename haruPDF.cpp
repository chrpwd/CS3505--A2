/* Christian Purdy
 * CS3505
 * A2 Classes & Facades
*/

#include"haruPDF.h"

using namespace std;

//prefix def with class name
HaruPDF::HaruPDF(char name [256])
{


	strcpy(filename, name);

	strcat (filename, ".pdf");

	set_page();

    

	
}

//sets up page, and fonts, called by constructor

    void HaruPDF::set_page()
    {
	pdf = HPDF_New (NULL, NULL);

    /* add a new page object. */
	this->page = HPDF_AddPage (pdf);
	HPDF_Page_SetSize (page, HPDF_PAGE_SIZE_A5, HPDF_PAGE_PORTRAIT);

//    print_grid  (pdf, page);
	font = HPDF_GetFont (pdf, "Helvetica", NULL);
	HPDF_Page_SetTextLeading (page, 20);
	HPDF_Page_SetGrayStroke (page, 0);

    /* text along a circle */

    	HPDF_Page_BeginText (page);

    // Their example sets font twice. Probably some kind of mistake. Fix it or do what they do.
    	font = HPDF_GetFont (pdf, "Courier-Bold", NULL);
    	HPDF_Page_SetFontAndSize (page, font, 30);

	buf[1] = 0;


    }

    //method to print characters to PDF
    void HaruPDF::writePDF(float x, float y, double rad, char c)
    {
        buf[0] = c;
        // This ugly function defines where any following text will be placed
        // on the page. The cos/sin stuff is actually defining a 2D rotation
        // matrix.
        HPDF_Page_SetTextMatrix(page, cos(rad), sin(rad), -sin(rad), cos(rad), x, y);

        HPDF_Page_ShowText (page, buf);
    }

    void HaruPDF::save()
    {
        HPDF_Page_EndText (page);
        
        /* save the document to a file */
        HPDF_SaveToFile (pdf, filename);
        
        /* clean up */
        HPDF_Free (pdf);
    }
