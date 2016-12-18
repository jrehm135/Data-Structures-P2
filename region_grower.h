#include "EasyBMP.h"
#include "linked_stack.h"


class RegionGrower
{
public:
	
	void setImage(const char * filename);
	void setSeed(int x, int y);
	void setReplacement(int red, int green, int blue);
	void update();
	void getOutput(const char * filename);
private:
	BMP Input;
	int NewRed;
	int NewGreen;
	int NewBlue;
//	ebmpBYTE Temp;
	RGBApixel Start;
	RGBApixel NewCol;
	RGBApixel uppix;
	RGBApixel downpix;
	RGBApixel leftpix;
	RGBApixel rightpix;
	struct seed {
		int x;
		int y;
	};
	
	seed currpos;
	seed sprout;
};