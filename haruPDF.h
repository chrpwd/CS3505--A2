/* Christian Purdy
 * CS3505
 * A2 Classes & Facades
*/

#ifndef HARU_H //include guard
#define HARU_H

#include <stdlib.h>
#include <stdio.h>
#include<iostream>
#include<string>
#include "hpdf.h"
#include <string.h>
#include <math.h>

class HaruPDF
{
    private:
        char filename[256];
        HPDF_Doc pdf;
        HPDF_Page page;
        HPDF_Font font;
        char buf[2];
        void set_page();

    public:

        HaruPDF(char name[256]);
        void writePDF(float x, float y, double rad, char c);
        void save();
    
};
#endif //end include guard
