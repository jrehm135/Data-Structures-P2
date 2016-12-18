// implement your program here
#include "region_grower.h"

int main(int argc, char* argv[])
{
	RegionGrower build;

	char* fileIn = argv[1];
	int x = std::atoi(argv[2]);
	int y = std::atoi(argv[3]);
	int red = std::atoi(argv[4]);
	int green = std::atoi(argv[5]);
	int blue = std::atoi(argv[6]);
	char* fileOut = argv[7];
	//changes some of the cstr values to ints

	build.setImage(fileIn);
	build.setSeed(x, y);
	build.setReplacement(red, green, blue);
	build.update();
	build.getOutput(fileOut);

	return 0;
}
